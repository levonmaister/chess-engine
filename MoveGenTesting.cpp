#include <iostream>
#include <ctime>
#include<cstdlib>

#include "Player.h"
#include "AI.h"
using namespace std;

int main()
{
	
	srand(time(0));

	Player PlayerObj;
	BoardClass BoardObj;
	AI AIObj;

	string playermove;

	int randomnumber;
	bool HasGameEnded = false;

/*	AIObj.BSTMovegenerator.GenerateMoves();
	for (int x = 0; x < AIObj.BSTMovegenerator.getLength(); x++) {


		cout << AIObj.BSTMovegenerator.getMove(x) << endl;
	}
	*/

	while (!HasGameEnded) {

		// Print board after player move and beginning
		BoardObj.PrintUIChessBoard();


// AI PART

		// Check if we have any moves. Function pre generates moves
		if (AIObj.BSTMovegenerator.HaveTurnRanOutOfMoves()) { HasGameEnded = true; continue; }
		
		randomnumber = AIObj.RandomNumberGen();

		// Implement the move and give the move ID
		AIObj.ImplementMoveOnBoard(AIObj.BSTMovegenerator.movelist[randomnumber],
			AIObj.ImplementMoveFindID(AIObj.BSTMovegenerator.movelist[randomnumber]));

//Intersection AI -> Board -> Player
		// Transfer data
		BoardObj = AIObj;
		
		// Switch turn
		BoardObj.SwitchTurn();

		// Transfer data
		PlayerObj = BoardObj;

// Player Part
		// print AI move
		BoardObj.PrintUIChessBoard();

		// Check if game continues
		if (PlayerObj.HaveTurnRanOutOfMoves()) { HasGameEnded = true; continue; }

		// Input from player
		playermove = PlayerObj.InputPlayerMove();

		// Implement move
		PlayerObj.ImplementMoveOnBoard(playermove, PlayerObj.ImplementMoveFindID(playermove));

// Intersection Player->Board->AI

		// transfer board data
		BoardObj = PlayerObj;

		// Switch turn
		BoardObj.SwitchTurn();

		// transfer board data
		AIObj = BoardObj;
		AIObj.BSTMovegenerator = BoardObj;
	}



	cout << BoardObj.Turn << " just won" << endl;


	






	return 0;
}

