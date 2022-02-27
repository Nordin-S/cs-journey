/* 
# filnamn: MinaFuncs.cpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-04-14
# Senast ändrat: 2021-04-27
# Kurs: Objectbaserad Programmering
# Handledare: Jimmy Åhlander
 */

#include "MinaFuncs.hpp"

/*
# Reads from file <filename > and returns the results in
# a vector . Uses overloaded operator >>.
# @param filename The path to the file to be read .
# @returns vector < person > containing all the people listed
# in the file . An empty vector is returned if no people
# are found .
*/
std::vector<person> read_file(std::string filename) {
    std::vector<person> persons;
    person p;
    std::ifstream theTextfile(filename);

    if (theTextfile.is_open()){
        while ( theTextfile >> p ){
            persons.push_back(p);
        }
        theTextfile.close();
    }
    return persons;
}




/*
# Searches in vector <haystack > for names containing the
# substring <name_part >. Note that <name_part > is a
# a substring meaning exact matches are not necessary .
# The search is case insensitive .
# @param haystack The vector containing the people to
# search through .
# @param name_part The name to look for.
# @returns the number of people where name_part is found and
# occurs at least once .
*/
size_t find_in_names(std::vector<person> haystack, std::string name_part){
    size_t num = 0;
    std::string tempName = " ";
    transform(name_part.begin(), name_part.end(), name_part.begin(), ::tolower);
    for (person p : haystack){
        tempName = p.name;
        transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
        if (tempName.find(name_part) != std::string::npos){
            num++;
        }
    }
    return num;
}

/*
# Searches in vector <haystack> for people living in a
# particular <city>.
# The search is case insensitive .
# Exact matches only ( except case ).
# @param haystack The vector containing the people to
# search through .
# @param city The city to look for.
# @returns a vector containing all persons with exactly
# matching cities .
*/
std::vector<person> find_person_from_city(std::vector<person> haystack, std::string city){
    std::vector<person> foundPersons;
    std::string tempCity = " ";
    transform(city.begin(), city.end(), city.begin(), ::tolower);
    for (person p : haystack){
        tempCity = p.location.city;
        transform(tempCity.begin(), tempCity.end(), tempCity.begin(), ::tolower);
        if (tempCity == city){
            foundPersons.push_back(p);
        }
    }
    return foundPersons;
}

/*
# Overloads the operator >> to read from an istream , e.g. a
# file , to a person . Sets all the attributes of a person .
# @param in The istream data is read from .
# @param p The person to store data in.
# @returns a reference to the stream ( for operator chaining ).
*/
std::istream & operator >>(std::istream & in , person & p){ 
    std::string street, zip, city, adressLine;
    std::size_t commaPos;

    std::getline(in, p.name);
    std::getline(in, p.id);
    std::getline(in, adressLine);

    if (p.name == "" || p.id == "" || adressLine == ""){
        return in;
    }

    adressLine.erase(adressLine.find_last_not_of(" \n\r\t")+1);

    commaPos = adressLine.find(',');
    street = adressLine.substr(0, commaPos);
    
    zip = adressLine.substr(commaPos+2, 3);
    zip += adressLine.substr(commaPos+6, 2);

    city = adressLine.substr(commaPos+10);

    p.location.street = street;
    p.location.zip = std::stoi(zip);
    p.location.city = city;

    return in;
}

/*
# Overloads the operator << to write to an istream , e.g. a
# console, for find_person_from_city. Prints attributes: id, name and city.
# @param in The ostream to stream to.
# @param p The person data to read from.
# @returns a reference to the ostream ( for operator chaining ).
*/
std::ostream & operator <<(std::ostream & os, person p){
	os << p.id << ", " << p.name << ", " << p.location.city << std::endl;
	return os;
}


void DrawMenu(){
    ClearConsole();
    DrawMSG("Sök efter en person med hjälp av namn eller plats(kommun)");
    std::cout << "1. Sök del av personnamn." << std::endl;
    std::cout << "2. Sök efter personer i stad (endast exakta matchningar)." << std::endl;
    std::cout << "3. Avsluta" << std::endl;
}

/*
# Making sure to get expected input from user, e.g 
# string(A-ZÅÄÖa-zåäö) or only digits.
# @param isString bool value that sets expectation rule.
# @returns a string variable containing the user input (for menu selection or person search)
*/
// makes sure to get input based on what is expected, int or string otherwise complain
std::string GetInput(bool isString){
    std::string strTemp = "";
    const std::regex INT_REGEX("[[:digit:]]");
    const std::regex STR_REGEX("[A-ZÅÄÖa-zåäö]+[ ]*[A-ZÅÄÖa-zåäö]*");

    while (true){
		while (!std::getline(std::cin, strTemp, '\n')){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

        if(strTemp == ""){
            if(isString){
                BadInputMSG("En sträng förväntas som inmattning!");
            }else{
                BadInputMSG("Siffra förväntas som inmattning!");
            }
            continue;
        }
        if(std::regex_match(strTemp, STR_REGEX) && isString){
            return strTemp;
        }else if(std::regex_match(strTemp, INT_REGEX) && isString == false){
            return strTemp;
        }else{
            BadInputMSG("Vänligen mata in det som förväntas!");
            continue;
        }
    }
}

/*
# Outputs a colorcoded custom message or generic message on bad inputs
# @param customMSG string to output to std::cout.
*/
void BadInputMSG(std::string customMSG){
    if (customMSG != ""){
        std::cout << "\033[1m\033[33m" << customMSG << "\033[0m" << std::endl;
    }else{
        std::cout << "\033[1m\033[31mERROR: fel inmatning, vänligen försök igen.\033[0m" << std::endl;
    }
}

/*
# Expexting user to press enter(\n) to continue execution of code
*/
void EnterToContinue(){
    std::cout << "\033[1m\033[32mTryck enter för att fortsätta.\033[0m";   
    while (std::cin.get() != '\n')    {    
        std::cout << "\033[1m\032[35mTryck enter för att fortsätta.\033[0m";   
    }
}    

/*
# Outputs a colorcoded custom message
# @param msg string to output to std::cout.
*/
void DrawMSG(std::string msg){
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::cout << "\033[1m\033[35m            " << msg << "\033[0m" <<std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;       
}

/*
# Clears console based on OS
*/
void ClearConsole(){
    #ifdef WINDOWS
        std::system("cls");
    #else
        std::system ("clear");
    #endif
}