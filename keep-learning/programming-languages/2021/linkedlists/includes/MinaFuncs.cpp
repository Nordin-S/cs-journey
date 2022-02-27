/*
# filnamn: MinaFuncs.cpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-05-01
# Senast ändrat: 2021-08-23
# Kurs: Objectbaserad Programmering
# Labb: L2_Länkade listor
# Handledare: Jimmy Åhlander
 */
#include "MinaFuncs.hpp"

/*
# Default constructor
# Initializes the head and tail pointer for new objects
*/
linked_list::linked_list(){
    head = tail = nullptr;
}

/*
# Copy constructor creates a new object by feeding it another
# @param "src" referenced constant of type linked_list,
# used to create a new object from
*/
linked_list::linked_list(const linked_list &src){
    head = tail = nullptr;
	copyFromSrc(src, false);
}

/*
# Destructor, calls emptyList() to clear this list of all elements.
*/
linked_list::~linked_list(){
	emptyList();
}

/*
# emptyList, calls pop_front() to pop all elements from this list.
*/
void linked_list::emptyList(){
	while (!is_empty()){
		pop_front();
	}
}

/*
# Assignment operator, assigning rhs to lhs and returns this for chaining if
# need be.
# @param "rhs" referenced constant of type linked_list.
# @returns reference to this of type linked_list.
*/
linked_list& linked_list::operator=(const linked_list &rhs){
	// assign rhs to lhs if not same list
	if(this != &rhs){
		emptyList(); // empty left list with pop_front
		copyFromSrc(rhs, false); // deep copy right list with push_back into left list
	}
	return *this;
}

/*
# Concatination operator, append rhs to lhs and returns this for chaining if
# 	need be.
# @param "rhs" referenced constant of type linked_list.
# @returns reference to this of type linked_list.
*/
linked_list& linked_list::operator+=(const linked_list &rhs){
	// appends elements from rhs if not same list
	if(this != &rhs){
		copyFromSrc(rhs, false);
	}else if(this == &rhs){
		copyFromSrc(rhs, true);
	}

	return *this;
}

/*
# Deep linked_list copy maker
# Copy each node elements value from src with push_back into this object.
# @param "src" referenced constant of type linked_list.
# @param "is_same_list" of type bool.
*/
void linked_list::copyFromSrc(const linked_list &src, bool is_same_list){
	node* to_pos = nullptr;
	if(is_same_list){to_pos = src.tail;} // to concatenate to same list till last node -1
	for(node* loopSrc = src.head; loopSrc != to_pos; loopSrc = loopSrc->next){
		push_back(loopSrc->value);
	}
	if(to_pos != nullptr){ //push_back the last node element
		push_back(to_pos->value);
	}
}

/*
# Insert new nodes in object, making use of push_back and
# push_front when needed.
# @param "value" of type double for new node.
# @param "pos" of type size_t for where to insert new node.
*/
void linked_list::insert(double value, size_t pos){
	if (pos == 0) {
		push_front(value);
	}else if(pos >= size()-1){
		push_back(value);
	}else{
		node* n = new node(value);
		node* temp = head;
		size_t count = 0;

		// find where to insert new node
		while(temp != nullptr){
			if(count == pos){
				break;
			}
			temp = temp->next;
			count++;
		}
		n->next = temp;
		n->prev = temp->prev;
		n->prev->next = n;
		temp->prev = n;
	}
}

/*
# Push_front, add new node to this object.
# @param "value" of type double for new node.
*/
void linked_list::push_front(double value){
	node* n = new node(value);

	if (is_empty()) {
		head = tail = n;
	}else{ // push_front
		n->next = head;
		head->prev = n;
		head = n;
	}
}

/*
# Push_back, add new node to this object.
# @param "value" of type double for new node.
*/
void linked_list::push_back(double value){
	node* n = new node(value);

	if (is_empty()) {
		head = tail = n;
	}else{	// push_back
		n->prev = tail;
		tail->next = n;
		tail = n;
	}
}

/*
# Front, returns current heads value.
# @returns a value of type double.
*/
double linked_list::front() const{
	return head->value;
}

/*
# back, returns current tails value.
# @returns a value of type double.
*/
double linked_list::back() const{
	return tail->value;
}

/*
# At, returns given positions node value.
# @param "pos" of type size_t.
# @returns a value of type double.
*/
double linked_list::at(size_t pos) const{
	node* current = head;
	size_t count = 0;
	double returnValue = 0;

	while(current != nullptr){
		if(count == pos){
			returnValue = current->value;
			break;
		}
		count++;
		current = current->next;
	}
	return returnValue;
}

/*
# Removes node on given position, also makes use of pop_front and
# pop_back when needed.
# @param "pos" of type size_t.
*/
void linked_list::remove(size_t pos){
	if (pos == 0){
		pop_front();
	}else if (pos >= size()-1){
		pop_back();
	}else{
		node* toDelete = head;
		node* prevNode;
		node* nextNode;
		size_t count = 0;

		do{
			count++;
			toDelete = toDelete->next;
		}while (count != pos);

		prevNode = toDelete->prev;
		nextNode = toDelete->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete toDelete;
	}
}

/*
# Pop_front deletes the first node in the list.
# @returns the deleted items value of type double.
*/
double linked_list::pop_front(){
	return pop(head);
}
/*
# Pop_back deletes the last node in the list.
# @returns the deleted items value of type double.
*/
double linked_list::pop_back(){
	return pop(tail);
}

/*
# Pop deletes the first or last node in the list.
# @param "&pt" requires a node pointer.
# @returns the deleted items value of type double.
*/
double linked_list::pop(node* &pt){
	node* toDelete = pt;
	double toDeletesValue = 0;

	toDeletesValue = toDelete->value;

	if(size() > 1){
		if(toDelete == head){
			head = head->next;
			head->prev = nullptr;
		}else{
			tail = tail->prev;
			tail->next = nullptr;
		}
	}else{
		head = tail = nullptr;
	}
	delete toDelete;

	return toDeletesValue;
}

/*
# Size, counts all elements in the list and return the amount.
# @returns amount of elements in this list as type size_t.
*/
size_t linked_list::size() const{
	node* temp = head;
	size_t count = 0;
	for(; temp != nullptr; temp = temp->next){
		count++;
	}
	return count;
}

/*
# Is_empty, is this list empty or not.
# @returns "true" if list is empty or "false" if not as type bool.
*/
bool linked_list::is_empty() const{
	return (head == nullptr);
}

/*
# Print goes through all elements in this list and prints each elements value
# to the std::cout.
*/
void linked_list::print() const{
	for (node* pt = head; pt != nullptr; pt = pt->next) {
		std::cout << pt->value << " ";
	}
	std::cout << std::endl;
}

/*
# Print_reversed goes through all elements in this list in reversed and prints
# each elements value to the std::cout.
*/
void linked_list::print_reverse() const{
	for (node* pt = tail; pt != nullptr; pt = pt->prev) {
		std::cout << pt->value << " ";
	}
	std::cout << std::endl;
}

/*
# Node constructs a node and sets its value and pointers to nullptr.
# @param "value" of type double.
*/
linked_list::node::node(double value) {
    this->value = value;
	next = prev = nullptr;
}