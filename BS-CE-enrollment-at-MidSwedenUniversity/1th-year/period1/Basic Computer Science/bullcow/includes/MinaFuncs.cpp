/* 
# Created by: Nordin Suleimani
# Creation date: 2021-01-12
# Last changed: 2021-02-09
 */

#include "MinaFuncs.hpp"


void Greetings(unsigned int DIGIT_SIZE, unsigned int strWidth)
{
    bool isYes;

    ClearConsole();

    // say hello to user and ask if they want this program explained
    DrawTitle("                     Hi, and welcome to the Bulls and Cows game!");

    isYes = GetYesNoStringInput("Would you want me to explain how this game works? \n(Press y or n, for explanation or to skip) \n", strWidth);

    ClearConsole();
    // explain to the use what this program is ment to do, if no explaining is needed go on
    if (isYes)
    {
        DrawTitle("In this Bullcow game you will think of a \033[1m\033[92m" + std::to_string(DIGIT_SIZE) + "\033[0m digit secret code and I will guess \nwhat the number is. You will then give me a value reperesenting amount of \ncorrect digits in the right position(bulls) and similariy a value for each \ncorrect digit but that was not in the correct position (cows).\nOf course a 0 for no bulls or no cows. \n\ne.g comparing 4039 with 4293 will give 1 Bull and 2 Cows.");
        EnterToContinue();
        ClearConsole();
    }
}

bool StartGame(unsigned int NUM_RANGE, unsigned int DIGIT_SIZE, unsigned int strWidth)
{
    int attempts = 0;

    std::string newGuess;
    bool isYes;
    std::map<std::string, std::string> oldGuesses;

    ClearConsole();

    // the game begins SECTION
    DrawTitle("                  Let the games begin, think of a "+ std::to_string(DIGIT_SIZE) + " digit number.");
    EnterToContinue();
    ClearConsole();

    // Guessing starts now SECTION
    DrawTitle("                                 Guessing starts NOW");
    while (true)
    {    
        // generate a new guess
        newGuess = GenerateGuess(oldGuesses, NUM_RANGE, DIGIT_SIZE);

        //see if guess is still valid according to game rules
        if (newGuess.length() != DIGIT_SIZE || (unsigned)std::stoi(newGuess) > NUM_RANGE)
        {
            ClearConsole();
            // cheater title SECTION
            DrawTitle("      You damn cheater! Out of range and rules of the game, Bad Bad player!");
            std::cout << "Would you wanna play honestly this time or quit?" << std::endl;
            isYes = GetYesNoStringInput("Type y to start a new game or n to end the game. \n", strWidth);

            // start a new game
            if (isYes)
                return true;
            
            return false;
        }
         
        // show the guess and ask player if guess was right or not
        std::cout << "Is this your secret code: \033[1m\033[36m" << newGuess << "\033[0m?" << std::endl;
        attempts++;

        isYes = GetYesNoStringInput("If so please type y or n and hit Enter to end/continue game. \n", strWidth);

        // guess was correct, play again or farwell msg to player
        if (isYes)
        {
            ClearConsole();
            // guessed correctly SECTION
            DrawTitle("        I have correctly guessed you number after only just \033[1m\033[92m" + std::to_string(attempts) + "\033[0m attempt(s)!!");

            std::cout << "Would you wanna go again or quit? Type y or n and hit enter to continue." << std::endl;
            isYes = GetYesNoStringInput(" ", strWidth);

            // start a new game
            if (isYes)
                return true;
            
            return false;
        }
        else
        {
            //if guess is valid and not already exists in earlier guesses store it for later comparisions
            oldGuesses.insert(std::pair<std::string, std::string>(newGuess, GetBullsCows(true, DIGIT_SIZE)));
        }
    }
    return false;
}

void EndGame()
{
    // Ending the game SECTION
    DrawTitle("                             BULLS & COWS by Nordin.S                               \n\n                                      END                                           \n\n\033[1m\033[32mI will take over the world, HA HA HA! Thank you for playing, good bye!\033[0m"); 
}

// generate guess based on previous guesses
std::string GenerateGuess(std::map<std::string, std::string> G, const int NUM_RANGE, const int DIGIT_SIZE)
{
    std::string numString = "1023456789";
    int g = 0;
    int const START_GUESS = std::stoi(numString.substr(0, DIGIT_SIZE));

    if (G.empty())
        g = START_GUESS;
    else
        g = std::stoi(G.rbegin()->first) + 1;   
    
    while (!ValidGuess(std::to_string(g), G, DIGIT_SIZE) || HasDublicates(std::to_string(g)))
    {    
        g++;
        if (g > NUM_RANGE)
            break;
    }
    return std::to_string(g);
}

// guess validation, look if guess variation already exists
bool ValidGuess(std::string g, std::map<std::string, std::string> G, const int DIGIT_SIZE)
{
    for(const auto gi : G)
    {
        if (GetBullsCows(false, DIGIT_SIZE, g, gi.first) != gi.second)
            return false;
    }
    return true;
}

// return bullsCows based on computer guess or user input
std::string GetBullsCows(bool byUser, const int DIGIT_SIZE, std::string currentGuess, std::string oldGuess)
{
    int bulls = 0, cows = 0;
    std::string bullsCowsId = "";
    unsigned int strWidth = 1;

    if (byUser)
    {
        while(true)
        {
            while (true)
            {
                bulls = std::stoi(GetInput("Please tell me with a digit how many\033[1m\033[92m bulls\033[0m did I get: \n", strWidth, false));
                if(bulls < DIGIT_SIZE)
                    break;
                else if(bulls == DIGIT_SIZE)
                {
                    BadInputMSG("..." + std::to_string(bulls) + " bulls? Then I have allready guessed correctly, doh..");
                    exit(0);
                }
                BadInputMSG();
            }  

            while (true)
            {
                cows = std::stoi(GetInput("and how many \033[1m\033[92m cows \033[0m did I get: \n", strWidth, false));
                if(cows <= DIGIT_SIZE)
                    break;
                BadInputMSG();
            } 

            if ((cows + bulls <= DIGIT_SIZE) && !(bulls == (DIGIT_SIZE - 1) && cows == 1))
                break;
            
            BadInputMSG("It seems you have given me the wrong combination of values, please try again!");
        }
    }else
    {
        for(unsigned int i = 0; i < currentGuess.length(); i++)
        {
            if(oldGuess.find(currentGuess[i]) != std::string::npos)
            {
                if (currentGuess[i] == oldGuess[i])
                    bulls++;
                else
                    cows++;
            }
        }
    }
    bullsCowsId = std::to_string(bulls) + std::to_string(cows);
    return bullsCowsId;
}

// makes sure to get input based on what is expected, int or string otherwise complain
std::string GetInput(std::string msg, unsigned int strWidth, bool isString)
{
    std::string strTemp = "";

    const std::regex INT_REGEX("[[:digit:]]");
    const std::regex STR_REGEX("[A-Za-z]+");

    std::cout << msg;

    while (true)
    {
		while (!std::getline(std::cin, strTemp, '\n'))
		{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

        if(strTemp.length() <= 0 || strTemp.length() > strWidth)
        {
            if(isString)
                BadInputMSG("Expecting yes/y or no/n as input!");
            else
                BadInputMSG("Expecting a number as input!");
            continue;
        }

        if(std::regex_match (strTemp, STR_REGEX) && isString)
        {
            return strTemp;
        }
        else if(std::regex_match (strTemp, INT_REGEX))
        {
            return strTemp;
        }
        else
        {
            BadInputMSG("Please input what is expected of you!");
            continue;
        }
    }
}

bool GetYesNoStringInput(std::string msg, unsigned int strWidth)
{
    std::string isYes = "";
    while (true)
    {
        isYes = GetInput(msg, strWidth, true);

        if (isYes == "y" || isYes == "Y" || isYes == "yes" || isYes == "Yes")
            return true;
        else if (isYes == "n" || isYes == "N" || isYes == "no" || isYes == "No")
            return false;

        // output bad input if still looping 
        BadInputMSG("Expecting input y or n");
    }    
}

// checks if there is two or more of the same char in a string
bool HasDublicates(std::string str)
{
    unsigned int num = 0;
    for(unsigned int i = 0; i <= (str.length() - 1) ; i++)
    {
        for (unsigned int j = 0; j <= (str.length() - 1); j++)
        {
            if(str[i] == str[j])
                num++;
        }
        if(num > 1)
            return true;
        else
            num = 0;
    }
    return false;
}

// send a generic bad input message or a custom one.
void BadInputMSG(std::string customMSG)
{
    if (customMSG != "")
        std::cout << "\033[1m\033[31m" << customMSG << "\033[0m" << std::endl;
    else
        std::cout << "\033[1m\033[31mERROR: bad input, please try again.\033[0m" << std::endl;
}

void EnterToContinue()
{
    std::cout << "Press Enter to continue.";   
    while (std::cin.get() != '\n') 
    {    
        std::cout << "Press Enter to continue.";   
    }
}    

void DrawTitle(std::string titleText)
{
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::cout << titleText << std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;       
}

void ClearConsole()
{
    #ifdef WINDOWS
        std::system("cls");
    #else
        std::system ("clear");
    #endif
}