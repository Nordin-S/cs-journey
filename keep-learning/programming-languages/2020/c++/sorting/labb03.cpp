/*
# Created by: Nordin Suleimani
# Creation date: 2020-12-10
# Last changed: 2020-12-12
# Description: Takes in n number of nnumbers from two different files and ckecks if they are sorted,
# then merges both files into a new file but sorted.
*/

#include <iostream>
#include "./includes/headerfiles/ReadFileToVector.hpp"
#include "./includes/headerfiles/IsSorted.hpp"
#include "./includes/headerfiles/MergeFile.hpp"

using namespace std;

int main ()
{
    vector<int> a1File;
    vector<int> aFile;
    vector<int> bFile; 
    vector<int> cMergedFile; 
 
    ReadFileToVector("A1", a1File);
    ReadFileToVector("A", aFile);
    ReadFileToVector("B", bFile);

    cout << "Is A1 sorted: " << (IsSorted(a1File) ? "Yes!" : "No!") << endl;

    if ( IsSorted(aFile) && IsSorted(bFile) )
    {
        MergeFile(aFile, bFile);
        ReadFileToVector("C", cMergedFile);
        cout << "Is C sorted: " << (IsSorted(cMergedFile) ? "Yes!" : "No!") << endl;
    }else
        cout << "Could not merge A and B, one of them is not sorted." << endl;

    return 0;
}