/* 
# Created by: Nordin Suleimani
# Creation date: 2020-12-10
# Last changed: 2020-12-12
 */

#include <iostream>
#include <fstream>

#include "./headerfiles/MergeFile.hpp"

using namespace std;

void NewLineOrSpace(int &wordCount, ofstream &mergedFile, int wordPerLine = 10);

void MergeFile(vector<int> v1, vector<int> v2)
{
    auto v1i = v1.begin();
    auto v2i = v2.begin();

    int wordCount = 0;

    ofstream mergedFile("C");

    /* 
    Check if both vector pointers are not on end, if not compare current vector values, 
    output smaller value to merged file, increment the vector with current smaller value    
    */
    while(v1i != v1.end() && v2i != v2.end()) 
    {   
        if (*v1i < *v2i)
        { 
            mergedFile << *v1i;
            ++v1i;
        }else
        {
            mergedFile << *v2i;
            ++v2i;
        }
        NewLineOrSpace(wordCount, mergedFile);        
    }

    /* 
    Check with each loop if current vector has reached end if not output rest of values
    of the vector to the merged file.
    */
    while(v1i != v1.end()) 
    {
        mergedFile << *v1i;
        v1i++;

        NewLineOrSpace(wordCount, mergedFile);   
    }
    while(v2i != v2.end()) 
    {
        mergedFile << *v2i;
        v2i++;

        NewLineOrSpace(wordCount, mergedFile);   
    }    
}

void NewLineOrSpace(int &wordCount, ofstream &mergedFile, int wordPerLine)
{
    if (wordCount == wordPerLine)
    {
        wordCount = 0;
        mergedFile << endl;
    }else
    {
        mergedFile << " ";
        wordCount++;
    }    
}