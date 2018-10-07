/*
 * SNode.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: Omar Ahmad + Ahmad Tamimi
 */
#include "SNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

SNode::SNode(){ // this constructor reads values from the user inputs in the console ad sets up the node and its data by using the user's input in console.
	int rating;
	string comments;
	cout << "Enter a numerical rating: ";
	cin >> rating;
	cout << endl << "Enter any comments: ";
	cin >> comments;
	this->rating = rating;
	this->comments = comments;
	next = NULL;
}

SNode::SNode(int r, string c){ // this constructor reads values from parameter to set up the node and it's accompanying data
	this->rating = r;
	this->comments = c;
	next = NULL;
}

void SNode::printNode(){ // prints node information: Rating and comments, in one line.
	cout << "Rating: " << rating << ", ";
	cout << "Comments: " << comments << endl;
}

SNode::~SNode(){ // this destructor warns the user if they delete a node that isn't at the end of its list;
	if(next != NULL){
		cout << "deleting " << rating << ", " << comments << endl;
	}
}
