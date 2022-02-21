/* 
# Created by: Nordin Suleimani
# Creation date: 2021-01-12
# Last changed: 2021-02-09
 */

#ifndef MINA_FUNCS_HPP
#define MINA_FUNCS_HPP

#include <iostream>
#include <map>
#include <regex>
#include <limits>

void Greetings(unsigned int DIGIT_SIZE, unsigned int strWidth);
bool StartGame(unsigned int NUM_RANGE, unsigned int DIGIT_SIZE, unsigned int strWidth);
void EndGame();
std::string GenerateGuess(std::map<std::string , std::string> G, const int NUM_RANGE, const int DIGIT_SIZE);
bool ValidGuess(std::string g, std::map<std::string, std::string> G, const int DIGIT_SIZE);
std::string GetBullsCows(bool = false, const int = 4, std::string = "0", std::string = "0");
bool HasDublicates(std::string str);
std::string GetInput(std::string msg, unsigned int strWidth = 1, bool isString = true);
bool GetYesNoStringInput(std::string msg, unsigned int strWidth);
void BadInputMSG(std::string customMSG = "");
void EnterToContinue();
void DrawTitle(std::string titleText);
void ClearConsole();

#endif