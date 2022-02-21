/* 
# Created by:: Nordin Suleimani
# Creation date: 2020-11-25
# Last changed: 2020-11-26
# Description: Managing text from file -- takes in name and surname and swaps order, figures out gender
                from last digits of identification number. Lastly takes the address and prints
                out each person line by line.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
    ifstream    myfile;
    ofstream    newFile;
    string      namn, personNummer, gender, adress;
    int         genderInt;

    myfile.open("names.txt");
    newFile.open("nyttnames.txt");

    while (getline(myfile, namn))
    {
        // remove last names and then remove first names from the variable name and put back in swaped order
        namn = namn.substr(namn.find(" ")+1) + ", " + namn.substr(0, namn.find(" "));

        
        // find the number in the social security number that describes 
        // the gender and set gender to the correct gender with [M] or [F]
        getline(myfile, personNummer);
        genderInt = stoi(personNummer.substr(8, 1)) % 2;

        if(genderInt == 1)
            gender = "[M]";
        else
            gender = "[F]";

        namn = namn + " " + gender;
        newFile << namn << endl;

        getline(myfile, adress);
        newFile << adress << endl;
    }
    
    myfile.close();
    newFile.close();
    return 0;
}