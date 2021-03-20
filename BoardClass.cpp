#include "BoardClass.h"



// UPDATE VARIABLE FUNCTIONS

void BoardClass::SetHasKingsMovedYet() 
{
	// If AI king hasnt moved yet look if it has moved now
	if (!HasAIKingMoved) { if (chessboard[7][4] != '5') { HasAIKingMoved = true; } }
	
	// If king hasnt moved yet look if it has moved now
	if (!HasplayerKingMoved) { if (chessboard[0][4] != '-5') { HasplayerKingMoved = true; } }
}

void BoardClass::SetHasTowersMovedYet() 
{
	// If Player left tower hasnt moved then 
	if (!HasplayerLeftTowerMoved) { if (chessboard[0][0] != '-1') { HasplayerLeftTowerMoved = true; } }
	// If player right tower hasnt moved then 
	if (!HasplayerRightTowerMoved) { if (chessboard[0][7] != '-1') { HasplayerRightTowerMoved = true; } }
	// If AI left tower hasnt moved then 
	if (!HasAILeftTowerMoved) { if (chessboard[7][0] != '1') { HasAILeftTowerMoved = true; } }
	// If AI right tower hasnt moved then
	if (!HasAIRightTowerMoved) { if (chessboard[7][7] != '1') { HasAIRightTowerMoved = true; } }
}




// Search Functions

// GETVALUE SEARCH FUNCTIONS

// input position output board value
int BoardClass::ScanGetValueN(int x, int y) { return chessboard[y+1][x]; };
int BoardClass::ScanGetValueS(int x, int y) { return chessboard[y-1][x]; };
int BoardClass::ScanGetValueW(int x, int y) { return chessboard[y][x-1]; };
int BoardClass::ScanGetValueE(int x, int y) { return chessboard[y][x+1]; };

int BoardClass::ScanGetValueNE(int x, int y) { return chessboard[y + 1][x + 1]; };
int BoardClass::ScanGetValueNW(int x, int y) { return chessboard[y + 1][x - 1]; };
int BoardClass::ScanGetValueSE(int x, int y) { return chessboard[y - 1][x + 1]; };
int BoardClass::ScanGetValueSW(int x, int y) { return chessboard[y - 1][x - 1]; };

int BoardClass::ScanGetValueHorse(int x, int y, int count) 
{
	switch (count) 
	{
	case 0:
		return chessboard[y + 1][x + 2];
	case 1:
		return chessboard[y-1][x + 2];
	case 2: 
		return chessboard[y+2][x+1];
	case 3:
		return chessboard[y+2][x-1];
	case 4:
		return chessboard[y+1][x-2];
	case 5:
		return chessboard[y-1][x-2];
	case 6:
		return chessboard[y-2][x+1];
	case 7:
		return chessboard[y-2][x-1];
	}

};

//GET CORDINATES SEARCH FUNCTIONS
string BoardClass::ScanGetCordinatesN(int x, int y) { return createmove(x, y + 1); }
string BoardClass::ScanGetCordinatesS(int x, int y) { return createmove(x, y - 1); };
string BoardClass::ScanGetCordinatesW(int x, int y) { return createmove(x - 1, y); };
string BoardClass::ScanGetCordinatesE(int x, int y) { return createmove(x + 1, y); };

// Scans Given position using Previous Scan Cordinate functions and returns cordinates
string BoardClass::ScanGetCordinatesNE(int x, int y) { return createmove(x + 1, y + 1); };
string BoardClass::ScanGetCordinatesNW(int x, int y) { return createmove(x - 1, y + 1); };
string BoardClass::ScanGetCordinatesSE(int x, int y) { return createmove(x + 1, y - 1); };
string BoardClass::ScanGetCordinatesSW(int x, int y) { return createmove(x - 1, y - 1); };

string BoardClass::ScanGetCordinatesHorse(int x, int y, int count)
{
	switch (count) 
	{
	case 0: return createmove(x + 2, y + 1);
	case 1: return createmove(x+2, y-1);
	case 2: return createmove(x+1, y+2);
	case 3: return createmove(x-1, y+2);
	case 4: return createmove(x-2, y+1);
	case 5: return createmove(x-2, y-1);
	case 6: return createmove(x+1, y - 2);
	case 7: return createmove(x-1, y - 2);
	};
};

// General scan
int BoardClass::ScanGetValueGeneral(int x, int y) { return chessboard[y][x]; };


int BoardClass::ImplementMoveFindID(string move){
	string KingCastleMoves[4] { "+4+0+7+0","+4+0+0+0","+4+7+7+7","+4+7+0+7" };
	for (int x = 0; x < 4; x++) { if (KingCastleMoves[x] == move) { return 101; } }
	if (abs(chessboard[oldy(move)][oldx(move)]) == 6) {
		if (newy(move) == 7 || newy(move) == 0) { return 99; }
	}
	
	return 100;

}


// Implement final move
	// ID = 100 basic move
	// ID = 99 Pawn has reached end of board
	// ID = 101 king has castled
void BoardClass::ImplementMoveOnBoard(string move, int MoveID) {

	int turnk = 1;

	if (Turn == "player") { turnk = -1; }

	// pawn has reached end of board
	if(MoveID<100){
		chessboard[oldy(move)][oldx(move)] = 0;
		chessboard[newy(move)][newx(move)] = turnk*4;
	}

	// King castle move
	else if(MoveID>100){
		// Identify which side it is moving
		// right side move
		if (oldx(move) < newx(move)) {
			// remove old
			chessboard[oldy(move)][oldx(move)] = 0;
			chessboard[newy(move)][newx(move)] = 0;

			chessboard[oldy(move)][6] = 5 * turnk;
			chessboard[newy(move)][5] = 1 * turnk;
		}
		// left side
		else {
			// remove old
			chessboard[oldy(move)][oldx(move)] = 0;
			chessboard[newy(move)][newx(move)] = 0;

			chessboard[oldy(move)][2] = 5 * turnk;
			chessboard[newy(move)][3] = 1 * turnk;
		}
	}
	//Regular move
	else {
		int ID = chessboard[oldy(move)][oldx(move)];
		chessboard[oldy(move)][oldx(move)] = 0;
		chessboard[newy(move)][newx(move)] = ID;
	}

}



// Fen to board class, takes the FEN notation and the boardclass which we want to change the board and its properties
void BoardClass::FenToBoard(string FEN, const BoardClass obj) {

	// 8 rows reserved for the board
	// 1 row for turn
	// 1 row for king castle properties indicators
	string FENArray[10];
	char space = ' ';
	char end = '/';

	bool loopcontinue = true;
	int loopcounter = 0;
	int Layer = 0;

	while (loopcontinue) {

		// Going through the board and 
		if(Layer<=7 && Layer>=0){
		
		}

	}
	
}

