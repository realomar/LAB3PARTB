/*
 * SNode.hpp
 *
 *  Created on: Oct 6, 2018
 *      Author: CISC220 LAB3
 */

#ifndef SNODE_HPP_
#define SNODE_HPP_
#include <iostream>
using namespace std;

class SNode{
	friend class SLL; //SLL can access the functions and variables inside SNode
	int rating; //Two types of data, one is rating
	string comments; //The other is comments
	SNode *next;

public:
	//Constructors:

	SNode();
	SNode(int r, string c);

	//Destructor:

	~SNode();

	//Methods:

	void printNode();

};
#endif /* SNODE_HPP_ */
