#include "Player.h"


string Player::InputPlayerMove(){

	GenerateMoves();



	int ox, oy, nx, ny;
	string move;

	do {
		cout << "input oldx, oldy, newx, newy " << endl;

		cin >> ox;
		cin >> oy;
		cin >> nx;
		cin >> ny;

		move = createmove(ox, oy, nx, ny);
	} while (!IsPlayerMoveLegal(move));

	return move;

}


bool Player::IsPlayerMoveLegal(string move) {

	for (int x = 0; x < getLength(); x++) {
		if (movelist[x] == move) { return true; }
	}
	return false;

}


