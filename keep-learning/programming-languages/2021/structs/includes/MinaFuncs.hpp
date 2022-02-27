/* 
# filnamn: MinaFuncs.hpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-04-14
# Senast ändrat: 2021-04-27
# Kurs: Objectbaserad Programmering
# Handledare: Jimmy Åhlander
 */

#ifndef MINA_FUNCS_HPP
#define MINA_FUNCS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>


struct adress {
	std::string street;
	int zip;
	std::string city;
};

struct person {
	std::string name;
	std::string id;
	adress location;
};


std::vector<person> read_file(std::string filename);
size_t find_in_names(std::vector<person> haystack, std::string name_part);
std::vector<person> find_person_from_city(std::vector<person> haystack, std::string city);
std::istream & operator >>(std::istream & in, person & p);
std::ostream & operator <<(std::ostream & os, person p);


void DrawMenu();
std::string GetInput(bool isString = true);
void BadInputMSG(std::string customMSG = "");
void EnterToContinue();
void DrawMSG(std::string titleText);
void ClearConsole();
#endif