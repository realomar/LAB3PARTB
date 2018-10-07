/*
 * SLL.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: Omar Ahmad + Ahmad Tamimi
 */
#include <iostream>
#include <stdlib.h>
#include "SLL.hpp"
#include "SNode.hpp"
using namespace std;

SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}

SLL::~SLL(){
	SNode *i = first;
	while (first != NULL){ //keeps deleting the first node of the
		i = first->next;   //linked list until there are no more.
		delete first;
		first = i;
		size--;
	}
}

void SLL::printSLL(){ //Prints out the linked list.
	SNode *i = first;
	while(i != NULL){
		i->printNode();
		i = i->next;
	}
	cout << endl;
}

void SLL::insertInOrder(int r, string c){
	//This method creates an ordered linked list (ordered by the rating). If the
	//linked list is empty, it calls addFirst with r and c. If the rating is less
	//than the first node’s rating in the list, it calls addAtFirst. If the
	//rating is greater than the last node’s rating, it calls the push method.
	//Otherwise it creates a new node using r and c, and inserts that node in
	//order into the linked list.

	if(first == NULL){
		addFirst(r,c);
	}

	else if(r < first->rating){
		addAtFront(r,c);
	}

	else if(r > last->rating){
		push(r,c);
	}

	else{
		SNode *i = first;
		while(i->next != NULL){
			if(r > i->rating && r < i->next->rating){
				SNode *s = new SNode(r,c);
				s->next = i->next;
				i->next = s;
			}
			else{
				i = i->next;
			}
		}
	}
}

void SLL::push(int r, string c){ //pushes a new node (with rating r and c comments) onto the end of the linked list
	SNode *i = new SNode(r,c);
	last->next = i;
	last = i;
	size++;
}

void SLL::addAtFront(int r, string c){ // adds a new node (made from r and c) to the beginning of the  list (remember to reset the first pointer) – I called this from inserInOrder(int r, string c) function
	SNode *i = new SNode(r,c);
	i->next = first;
	first = i;
	size++;
}

void SLL::addFirst(int r, string c){ //adds the very first node (made from r and c) to an empty list
	SNode *i = new SNode(r,c);
	first = last = i;
	size = 1;
}

int SLL::pop(){ //removes the last node from the linked list, and returns the rating from the node removed
	if (size > 0) {
	int returnVal = last->rating;

	if (first != last ){
		SNode *x = first;

		for (int i = 0; i < size-1;i++) {
			x = x->next;
		}
		delete last;
		last = x;
		last->next = NULL;
	}

	else {
		delete last;
		first = NULL;
		last = NULL;
	}
	size --;
	return returnVal;
	}

	else {
		return -1;
	}
}

double SLL::getAve(){ //calculates the average rating (by traversing the list) and then returns the average rating.
	SNode *i = first;
	double total = 0;
	while(i->next != NULL){
		total += i->rating;
		i = i->next;
	}
	return total / (double) size;
}
