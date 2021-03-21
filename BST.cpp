#include "BST.h"
#include <iostream>
#include <ctime>
#include<cstdlib>

int BST::RandomNumberGen(int max) {


	int randy;

	randy = rand() % max;
	return randy;


}



void BST::CreateTree(){

	rootptr = new Node(this);


}

void BST::DeleteTree() {
	delete rootptr;

}