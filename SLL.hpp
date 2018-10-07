/*
 * SLL.hpp
 *
 *  Created on: Oct 6, 2018
 *      Author: CISC220 LAB3
 */

#ifndef SLL_HPP_
#define SLL_HPP_

#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class SLL{
	SNode *first;
	SNode *last;
	int size;

public:
	SLL();
	~SLL();
	void printSLL();
	void insertInOrder(int r, string c);
	void push(int r, string c);
	void addAtFront(int r, string c);
	void addFirst(int r, string c);
	int pop();
	double getAve();
};


#endif /* SLL_HPP_ */
