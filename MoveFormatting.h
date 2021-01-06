#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class MoveFormatting
{
private:

public:
	int newx(string a);
	int newy(string a);
	int oldx(string a);
	int oldy(string a);
	string createmove(int oldX=0, int oldY=0, int newX=0, int newY=0);

};




