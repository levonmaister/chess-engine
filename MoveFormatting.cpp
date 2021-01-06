
#include "MoveFormatting.h"

// In form +x+y+x+y

int MoveFormatting::newx(string a)
{
	int minusindicator = 1;
	int returnvalue;
	stringstream l;
	if (a[4] == '-') { minusindicator = -1; }
	l << a[5];
	l >> returnvalue;
	return returnvalue * minusindicator;
}

int MoveFormatting::newy(string a)
{
	int minusindicator = 1;
	int returnvalue;
	stringstream l;
	if (a[6] == '-') { minusindicator = -1; }
	l << a[7];
	l >> returnvalue;
	return returnvalue * minusindicator;
}
int MoveFormatting::oldx(string a)
{
	int minusindicator = 1;
	int returnvalue;
	stringstream l;
	if (a[0] == '-') { minusindicator = -1; }
	l << a[1];
	l >> returnvalue;
	return returnvalue * minusindicator;
}

int MoveFormatting::oldy(string a)
{
	int minusindicator = 1;
	int returnvalue;
	stringstream l;
	if (a[2] == '-') { minusindicator = -1; }
	l << a[3];
	l >> returnvalue;
	return returnvalue * minusindicator;
}


// Perfect
string MoveFormatting::createmove(int oldX, int oldY, int newX, int newY)
{
	stringstream l;
	// Inputting the first cordinate
	if (oldX >= 0) { l << '+' << oldX; }
	else { l << oldX; }
	// Second
	if (oldY >= 0) { l << '+' << oldY; }
	else { l << oldY; }
	// Third
	if (newX >= 0) { l << '+' << newX; }
	else { l << newX; }
	// Fourth
	if (newY >= 0) { l << '+' << newY; }
	else { l << newY; }

	string s;
	l >> s;

	return s;
}

