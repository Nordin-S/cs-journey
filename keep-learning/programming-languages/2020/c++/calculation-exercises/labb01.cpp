/* 
# Created by Nordin Suleimani
# Creation date: 2020-11-25
# Last changed: 2020-11-26
# Description: Find min, max och averate from given list of numbers
 */

#include <iostream>
using namespace std;


int main ()
{
    int num, max, min, sum, iteration;
    num = max = min = sum = iteration = 0;
    
    float average = 0.0f;

    while (cin >> num)
    {
        //initialisera alla variablar med första talet för att börja jämnföra senare
        //init all variables with first value, assuming it being the only value
        if (iteration == 0)
            min = max = num;
        
        //max value
        if (num > max)
            max = num; 
        //min value
        if (num < min)
            min = num;

        sum += num; 
        iteration++;            
    }
    average = (float)sum / (float)iteration;

    cout << "Max value: "  << max << ", Min value: "  << min << ", average value: " << average <<endl;

    return 0;
}    
