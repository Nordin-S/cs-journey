/*
# filnamn: main.cpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-05-01
# Senast ändrat: 2021-08-23
# Kurs: Objectbaserad Programmering
# Labb: L2_Länkade listor
# Handledare: Jimmy Åhlander
*/
#include "./includes/MinaFuncs.hpp"

/*
# Print_list is a global function that uses object member print() with the dot
# operator to print values of all elements in the given list.
# @param "l" of type linked_list.
*/
// void print_list(const linked_list &l){ ?????
void print_list(linked_list l){
	l.print();
}

/*
# merge a global function that merges two lists into one by poping the front
# of the list with smallest value and pushing it into the new list. Lastly
# concatinating with the operator =+ the list with remaining elements.
# @param "&list1" of type linked_list.
# @param "&list2" of type linked_list.
# @returns a list of type linked_list.
*/
linked_list merge(linked_list &list1, linked_list &list2){
	linked_list temp;

	while(!list1.is_empty() && !list2.is_empty()){
		if(list1.front() < list2.front()){
			temp.push_back(list1.pop_front());
		}else{
			temp.push_back(list2.pop_front());
		}
	}

	// concatenate the list with remaining nodes
	(list1.is_empty()) ? temp += list2 : temp += list1;
	return temp;
}

/*
# Is_sorted, global function that checks if given list is sorted in ascending
# order.
# @param "&l" as a const reference of type linked_list.
# @returns a true or false with bool type.
*/
bool is_sorted(const linked_list &l){
	if(l.size() > 1){
		for(size_t i = 0; i < l.size()-1; i++){
			if (l.at(i) <= l.at(i+1)){
				continue;
			}else{
				return false;
			}
		}
	}
	return true;
}

int main (){
    srand((unsigned) time(0));
    linked_list listOne;
    linked_list listTwo;
    listOne.push_back(0.0);
    listTwo.push_back(0.0);

    // Fill two lists with 50 ascending random numbers, each new random number
    // should be equal to previous number plus 0-4 bigger.
    double randm;
    for (int i = 0; i <= 48; i++){
        randm = listOne.at(i) + ((double) rand() / (RAND_MAX)) * 4;
        listOne.push_back(randm);

        randm = listTwo.at(i) + ((double) rand() / (RAND_MAX)) * 4;
        listTwo.push_back(randm);
    }
    std::cout << "-------1.push back" << std::endl;
    std::cout << "listOne: " << std::endl;
    listOne.print();
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "listTwo: " << std::endl;
    listTwo.print();
    std::cout << "=========================================" << std::endl;

    // Compare the 25th elements value in two lists and remove the element which
    // is the larger one from it's list.
    std::cout << "-------2.at and remove" << std::endl;
    if(listOne.at(24) >= listTwo.at(24)){
        listOne.remove(24);
        std::cout << "25th node from 'listOne' was removed: " << std::endl;
        listOne.print();
    }else{
        listTwo.remove(24);
        std::cout << "25th node from 'listTwo' was removed: " << std::endl;
        listTwo.print();
    }
    std::cout << "=========================================" << std::endl;

    // Use the assignement operator assign the smaller list to a newly declared
    // list then print out the new list in reversed with print_reverse().
    std::cout << "-------3.operator=" << std::endl;
    linked_list listThree;
    if(listOne.size() < listTwo.size()){
        listThree = listOne;
        std::cout << "ListThree is now the same as listOne" << std::endl;
    }else{
        listThree = listTwo;
        std::cout << "ListThree is now the same as listTwo" << std::endl;
    }
    listThree.print_reverse();
    std::cout << "=========================================" << std::endl;

    // Remove every other element from the list which is bigger and print out
    // the list with the global function print_list().
    std::cout << "----4.pop back and push front and 5.print list" << std::endl;
    if(!listOne.is_empty() && !listTwo.is_empty()){
        if(listOne.size() > listTwo.size()){
            for (int i = 0; i <= 24; i++){
                listOne.pop_back();
                listOne.push_front(listOne.pop_back());
            }
            std::cout << "listOne: " << std::endl;
            print_list(listOne); // <----------------------------- print_list
            std::cout << std::endl;
        }else{
            for (int i = 0; i <= 24; i++){
                listTwo.pop_back();
                listTwo.push_front(listTwo.pop_back());
            }
            std::cout << "listTwo: " << std::endl;
            print_list(listTwo); // <----------------------------- print_list
        }
    }
    std::cout << "=========================================" << std::endl;

    // Merge two lists and check if they are sorted in ascending order.
    std::cout << "-------6.merge and 7.sort" << std::endl;
    linked_list merged_list = merge(listOne, listTwo);
    std::cout << "Given lists are combined and "
        << ((is_sorted(merged_list))? "sorted" : "not sorted")
        << " containing "<< merged_list.size() << " elements." << std::endl;
    std::cout << "=========================================" << std::endl;

    // testing concatination on same list :)
    merged_list += merged_list;
    std::cout   << "Fix: concatinating last merged list with itself, now "
                << "contains "<< merged_list.size() << " elements." << std::endl;
    std::cout << "=========================================" << std::endl;
    return 0;
}
