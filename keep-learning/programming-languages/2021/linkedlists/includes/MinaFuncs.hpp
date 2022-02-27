/*
# filnamn: MinaFuncs.hpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-05-01
# Senast ändrat: 2021-08-23
# Kurs: Objectbaserad Programmering
# Labb: L2_Länkade listor
# Handledare: Jimmy Åhlander
 */
#ifndef MINA_FUNCS_HPP
#define MINA_FUNCS_HPP

#include <iostream>

class linked_list {
	private:
	struct node{
		node(double value);
		double value;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;

	public:
	linked_list();
	linked_list(const linked_list &src);
	~linked_list();
	linked_list& operator=(const linked_list &rhs);

	// appends elements from rhs
	linked_list& operator+=(const linked_list &rhs);
	void copyFromSrc(const linked_list &src, bool is_same_list);

	// inserting elements
	void insert(double value , size_t pos);
	void push_front(double value);
	void push_back(double value);

	// accessing elements
	double front() const;
	double back() const;
	double at(size_t pos) const;

	// removing elements
	void remove(size_t pos);
	double pop_front();
	double pop_back();
	double pop(node* &pt);

	// status
	size_t size() const;
	bool is_empty() const;

	// output
	void print() const;
	void print_reverse() const;
	void emptyList();
};
void print_list(linked_list l);
linked_list merge(linked_list &list1, linked_list &list2);
bool is_sorted(const linked_list &l);
#endif