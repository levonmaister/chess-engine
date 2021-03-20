#include <iostream>
#include <ctime>
#include<cstdlib>

#include "Player.h"
#include "AI.h"
using namespace std;

int main()
{


	AI aiobj;
	cout << "creating tree" << endl;
	aiobj.CreateTree();
	cout << "tree created" << endl;

cout << aiobj.rootptr->NodePtr[0]->NodePtr[0]->NodePtr[0]->NodePtr.size() << endl;

	cout << "deleting tree" << endl;
	aiobj.DeleteTree();
	cout << "tree deleted" << endl;


	cout << "hi" << endl;
	return 0;
}

