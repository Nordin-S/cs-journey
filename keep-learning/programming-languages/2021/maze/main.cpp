/*
# filnamn: main.cpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-05-01
# Senast ändrat: 2021-10-18
# Kurs: Objectbaserad Programmering
# Handledare: Jimmy Åhlander
# Betyg: C
*/

#include "./includes/MinaFuncs.hpp"

bool GenerateMenu();
bool YesNoMenu(std::string);
int GetOddNumbers();
void Cls();

int main (){
	srand (unsigned (time(NULL)));

	while(true){
		if(GenerateMenu()){
			int inputRows = 11;
			int inputCols = 11;

			if(YesNoMenu("Own maze size?(y/Y or n/N)\nA size of atleast 5x5 is required!")){
				std::cout << "How many rows would you like?" << std::endl;
				inputRows = GetOddNumbers();
				std::cout << "How many columns would you like?" << std::endl;
				inputCols = GetOddNumbers();
			}

			Cls();
			CMazeGenerator maze(inputRows, inputCols);
			std::cout << std::endl;
			if(YesNoMenu("Would you like to solve this generated maze?(y/Y or n/N)")){
				Cls();
				maze.PrintMaze(maze.Solve());
				std::cout << std::endl;
				std::cout << "Hit enter to continue!" << std::endl;
				do{
				}while(std::cin.get() != '\n');
			}
			Cls();
		}else{
			break;
		}
	}
	return 0;
}

bool GenerateMenu(){
	std::cout << "-----------------------------------Menu-----------------------------------" << std::endl;
	std::cout << "Generate a maze(g/G)" << std::endl;
	std::cout << "Quit program(q/Q)" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::string menuChoice;
	std::cout << "Input: ";
	while (std::getline(std::cin, menuChoice)){
		if(menuChoice == "g" || menuChoice == "G"){
			return true;
		}else if(menuChoice == "q" || menuChoice == "Q"){
			return false;
		}else{
			std::cout << "Bad input, try again." << std::endl;
		}
	}
	return false;
}

bool YesNoMenu(std::string myMessage){
	std::string menuChoice;
	std::cout << myMessage << std::endl;
	std::cout << "Input: ";
	while (std::getline(std::cin, menuChoice)){
		if(menuChoice == "y" || menuChoice == "Y"){
			return true;
		}else if(menuChoice == "n" || menuChoice == "N"){
			return false;
		}else{
			std::cout << "Bad input, try again." << std::endl;
		}
	}
	return false;// douse nothing, only removes no return warning
}

int GetOddNumbers(){
	const std::regex intRegex("[0-9]+");
	std::string menuChoice;
	std::cout << "Input: ";
	while (std::getline(std::cin, menuChoice)){
		if(std::regex_match(menuChoice, intRegex)){
			int oddNumber = stoi(menuChoice);
			if(oddNumber % 2 != 0 && oddNumber >= 5)
				return oddNumber;
		}
		std::cout << "Bad input: try again, a odd number equal or larger than 5 is needed!" << std::endl;
		continue;
	}
	return 666;// douse nothing, only removes no return warning
}

// from the web
void Cls(){
	#if defined _WIN32
		system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
	#elif defined (__APPLE__)
		system("clear");
	#endif
}