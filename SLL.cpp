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

void SLL::printSLL(){
	SNode *i = first;
	while(i != NULL){
		first->printNode();
		i = i->next;
	}
}

void SLL::insertInOrder(int r, string c){
	SNode *i = first;
	if (i == NULL || r < i->rating) addFirst(r,c);
	else if(r > i->rating) push(r,c);

}

void SLL::push(int r, string c){
	SNode *i = new SNode(r,c);
	last->next = i;
	last = i;
	size++;
}

void SLL::addAtFront(int r, string c){
	SNode *i = new SNode(r,c);
	i->next = first;
	first = i;
	size++
}

void SLL::addFirst(int r, string c){
	SNode *i = new SNode(r,c);
	first = last = i;
	size = 1;
}

int SLL::pop(){
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

double SLL::getAve(){

}
