/* 
# Created by: Nordin Suleimani
# Creation date: 2020-12-14
# Last changed: 2020-12-17
# Description: Looks through the file "hitchhikersguide.txt" and figures out total word count.
                And displays a list of most common words and number of each accurance depening on 
                how many top accuring words the user wants to list.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex> 
#include <map>
#include <iterator>

using namespace std;

void TextClean_aToz(string fileName, vector<string> &txtFileToVector_ref, int &totalWordCount);
void WordFreqToMap(vector<string> &txtFileToVector_ref, map<string, int> &wordCountMap_ref);
void FlipMapToMultiMap(map<string, int> &wordCountMap_ref, multimap<int, string> &wordCountMultiMap_ref);
void DisplayWordCountFromMultiMap(multimap<int, string> &wordCountMultiMap_ref, int topWords);

// Global variables
string longestWord = "";

int main ()
{
    vector<string> txtFileToVector;
    map<string, int> wordCountMap;
    multimap<int, string> wordCountMultiMap;

    string fileName = "hitchhikersguide.txt";
    int totalWordCount = 0;
    int topWords = 10;

    cout << "---------------------File-Word-Counter---------------------" << endl; 
    cout << "Enter amount of occuring words you would like to display:" << endl;
    cin >> topWords;

    TextClean_aToz(fileName, txtFileToVector, totalWordCount);
    WordFreqToMap(txtFileToVector, wordCountMap);
    FlipMapToMultiMap(wordCountMap, wordCountMultiMap);

    cout << "--------------------------BEGIN----------------------------" << endl;  
    cout << "The file \"" << "\033[1m\033[33m" << fileName << "\033[0m\" has a total word count of "
        << "\033[1m\033[31m" << totalWordCount << "\033[0m words." << endl; 

    cout << "-- Of which the below \033[1m\033[31m" << topWords << "\033[0m words are the most common accurring:" << endl;
    DisplayWordCountFromMultiMap(wordCountMultiMap, topWords);
    cout << endl;  
    cout << "The last longest word in the file is \033[1m\033[35m" << longestWord << "\033[0m "<< endl; 
    cout << endl; 
    cout << "========================THE-END============================" << endl; 

    return 0;
}

void TextClean_aToz(string fileName, vector<string> &txtFileToVector_ref, int &totalWordCount)
{
    ifstream tempFile(fileName);
    string line = "";
    string word = "";

    //pull in each line from file, clean each line and push back into referenced vector word by word
    while (getline(tempFile, line))
    {
        if (line != "")
        {
            const regex regX("[^a-zA-Z\\s]+");
            line = regex_replace (line, regX, " ");
            
            transform(line.begin(), line.end(), line.begin(), ::tolower);

            // after regex line might be turned into two or more words.. therefore use ss stream to further break down.
            stringstream ss(line);
            while(ss >> word)
            {   
                if (word != "" && word != "\n")
                    {
                        // find the longest word
                        if (longestWord.size() < word.size() )
                            longestWord = word;                            
                        txtFileToVector_ref.push_back(word);
                        ++totalWordCount;    
                    }
            }
        }
    } 
    tempFile.close();
}

// add each word from vector to a map as frequency if it exists
void WordFreqToMap(vector<string> &txtFileToVector_ref, map<string, int> &wordCountMap_ref)
{   
    vector<string>::iterator it = txtFileToVector_ref.begin();
    while(it != txtFileToVector_ref.end()) {
        ++wordCountMap_ref[*it];
        it++;
    }
}

// enter each value/key pair in reversed order into a multimap due too maybe multiple words can exist with same frequency
void FlipMapToMultiMap(map<string, int> &wordCountMap_ref, multimap<int, string> &wordCountMultiMap_ref)
{
    for (map<string, int>::iterator i = wordCountMap_ref.begin(); i != wordCountMap_ref.end(); i++)
        wordCountMultiMap_ref.insert(pair<int, string>(i->second, i->first));
}

// Display value/key pair from multimapp in reverse since multimapp auto sorts in ascending order. 
// Display as many top words as user requires.
void DisplayWordCountFromMultiMap(multimap<int, string> &wordCountMultiMap_ref, int topWords)
{
    int n = 1;

	multimap<int, string>::reverse_iterator rit = wordCountMultiMap_ref.rbegin();
    cout << "===========================================================" << endl;
    cout << " WORD\t\t|ACCURANCE" << endl;
 	while (rit != wordCountMultiMap_ref.rend()) {
		cout << " \"\033[1m\033[33m"<< rit->second << "\033[0m\"\t\t| \033[1m\033[31m" << rit->first<< "\033[0m" << endl;
		rit++; 

        if (n == topWords)
            break;
        ++n;
	} 
    cout << "===========================================================" << endl;   
}
