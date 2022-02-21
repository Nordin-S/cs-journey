/* 
# Created by: Nordin Suleimani
# Creation date: 2021-01-12
# Last changed: 2021-02-09
# Description: A bullcow game where a user thinks of a number and the computer will guess the correct number 
# by asking the player to input amount of bulls(number of correct digits in the correct order and number of 
# cows for digits in the guess that are not in the correct order.)
 */

#include "./includes/MinaFuncs.hpp"

int main ()
{
    const std::string numString = "9876543210";
    const unsigned int DIGIT_SIZE = 4; // guess size of number e.g 3495 OBS, 10 digits is limit!
    
    // creates a number with unique digits that respects the DIGIT size variable
    const unsigned int NUM_RANGE = std::stoi(numString.substr(0, DIGIT_SIZE));
    const unsigned int strWidth = 3; // constant number used to limit input size    

    Greetings(DIGIT_SIZE, strWidth);
    while(true)
    {
        if(!StartGame(NUM_RANGE, DIGIT_SIZE, strWidth))
        {
            EndGame();
            break;
        }
    }
    return 0;
}