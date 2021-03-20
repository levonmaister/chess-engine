#include "BST.h"
#include <iostream>
#include <ctime>
#include<cstdlib>

int BST::RandomNumberGen() {


	int randy;
	int max = BSTMovegenerator.getLength();

	randy = rand() % max;
	return randy;


}



void BST::CreateTree(){

	rootptr = new Node(this);


}

void BST::DeleteTree() {
	delete rootptr;

}