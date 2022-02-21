/* 
# Created by: Nordin Suleimani
# Creation date: 2020-12-10
# Last changed: 2020-12-12
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "./headerfiles/ReadFileToVector.hpp"

using namespace std;

void ReadFileToVector(string fileName, vector<int> &tempVector)
{
    ifstream tempFile(fileName);
    string line = "";

    //pull in each line from file, use sstream and with yet another while loop grab each value and push into vector (back)
    while (getline(tempFile, line))
    {
        stringstream ss;
        ss << line;
        string str = "";
        while(ss >> str)
            tempVector.push_back(stoi(str));
    } 
    tempFile.close();
}