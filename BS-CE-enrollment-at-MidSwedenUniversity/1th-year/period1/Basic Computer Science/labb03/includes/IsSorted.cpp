/* 
# Created by: Nordin Suleimani
# Creation date: 2020-12-10
# Last changed: 2020-12-12
 */

#include <iostream>

#include "./headerfiles/IsSorted.hpp"

using namespace std;

// check with a while loop if current value is larger than next value, if not larger vector is sorted.
bool IsSorted(vector<int> &tempVector)
{
    vector<int>::iterator i = tempVector.begin();  // pointer iterator
    bool isSorted = true;
    int oldNum = *i; // currenter pointer value
    i++;
    while(i != tempVector.end() && isSorted) {
        // std::cout << oldNum << " and new num " << *i << endl;
        if (oldNum > *i)
            isSorted = false;
        oldNum = *i;
        i++;
    }
    return isSorted;
}