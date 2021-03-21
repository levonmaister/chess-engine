#include <iostream>
#include <ctime>
#include<cstdlib>

#include "Player.h"
#include "AI.h"
using namespace std;

int main()
{


	AI aiobj;
	cout << aiobj.GetMove();
	return 0;
}

