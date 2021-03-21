#pragma once
#include "MoveFormatting.h"
#include "Node.h"
class BoardClass : public MoveFormatting
{
public:
	// Needed for rules and movegeneration
	// -4 equals queen and -5 king
	
	// + equals AI and - equals player. 
	// AI starts, AI is white

	/* int chessboard[8][8]={{-1,-2,-3,-4,-5,-3,-2,-1 },
							{-6,-6,-6,-6,-6,-6,-6,-6},
							{0, 0, 0, 0, 0, 0, 0, 0 },
							{0, 0 ,0 ,0 ,0 ,0, 0, 0 },
							{0 ,0 ,0 ,0, 0, 0, 0, 0 },
							{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
							{6 ,6, 6 ,6 ,6, 6, 6, 6 },
							{1, 2, 3, 4, 5, 3, 2, 1}};
		*/

	// temp chess testboard
	 int chessboard[8][8]={{0, 0, 0, 0, 0, 0, 0, -5},
						 {0, 1, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 0, 0, 0, 0, 0},
						{0, 0 ,0 ,0 ,0 ,0, 0, 0},
						{0 ,0 ,0, 0, 0 ,0, 0, 0},
						{0 ,0 ,0 ,0, 0, 0, 0 ,0},
						{0 ,0, 0 ,0 ,0, 0, 0, 0},
						{5, 0, 0, 0, 0, 0, 0, 0} };
	
	
	string Turn = "AI";
	string OppositeTurn = "player";
	// 77
	bool HasAIRightTowerMoved = false;
	// 07
	bool HasAILeftTowerMoved = false;
	// 70
	bool HasplayerRightTowerMoved = false;
	// 00
	bool HasplayerLeftTowerMoved = false;
	// 47
	bool HasAIKingMoved = false;
	// 40
	bool HasplayerKingMoved = false;
	// Maybe has kingcastled yet bool variable?
	
	bool HasPlayerKingCastled = false;
	bool HasAIKingCastled = false;

	// Variable updates functions
	void SetHasKingsMovedYet();
	void SetHasTowersMovedYet();

	// Search Functions

	// GETVALUE SEARCH FUNCTIONS
	
	// input position output board value
	int ScanGetValueN(int x, int y);
	int ScanGetValueS(int x, int y);
	int ScanGetValueW(int x, int y);
	int ScanGetValueE(int x, int y);

	int ScanGetValueNE(int x, int y);
	int ScanGetValueNW(int x, int y);
	int ScanGetValueSE(int x, int y);
	int ScanGetValueSW(int x, int y);

	int ScanGetValueHorse(int x, int y, int count);
	
	//GET CORDINATES SEARCH FUNCTIONS
    string ScanGetCordinatesN(int x, int y);
    string ScanGetCordinatesS(int x, int y);
    string ScanGetCordinatesW(int x, int y);
    string ScanGetCordinatesE(int x, int y);

    // Scans Given position using Previous Scan Cordinate functions and returns cordinates
	string ScanGetCordinatesNE(int x, int y);
	string ScanGetCordinatesNW(int x, int y);
	string ScanGetCordinatesSE(int x, int y);
	string ScanGetCordinatesSW(int x, int y);

	string ScanGetCordinatesHorse(int x, int y, int count);

	// General scan
	int ScanGetValueGeneral(int x, int y);

	// ID = 100 basic move
	// ID = 99 Pawn has reached end of board
	// ID = 101 king has castled
	void ImplementMoveOnBoard(string move, int ID=100);

	int ImplementMoveFindID(string move);

	void SwitchTurn(){
		if (Turn == "AI") { Turn = "player"; OppositeTurn = "AI"; }
		else{ Turn = "AI"; OppositeTurn = "player"; }
    }

	// PrintChessBoard with Numbers
	void PrintChessBoard() {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				cout << chessboard[y][x] << "  ";
			}
			cout << endl;
	} 
		cout << endl << endl << endl;
	}


	// PrintChessBoard Board Converter
	void PrintUIChessBoard(){
		// 0th place = '0' 1st place = tower 2=bishop etc
		string AIPieceID[7] = { "0","R","K","B","Q","N","P" };
		string PlayerPieceID[7] = { "0","r","k","b" ,"q","n","p" };

		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {

				if (chessboard[y][x] < 0) { cout << PlayerPieceID[abs(chessboard[y][x])] << "  "; }
				else{ cout << AIPieceID[abs(chessboard[y][x])] << "  "; }
			}
			cout << endl;
		}
		cout << endl << endl << endl;

	}



	// FEN to BoardClass function
	void FenToBoard(string FEN, const BoardClass obj);


	// Operator overloading board package transmission


	void operator =(const BoardClass& CopySource) {
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				this->chessboard[x][y] = CopySource.chessboard[x][y];
			}
		}

		this->HasAIRightTowerMoved = CopySource.HasAIRightTowerMoved;
		this->HasAILeftTowerMoved = CopySource.HasAIRightTowerMoved;
		this->HasplayerRightTowerMoved = CopySource.HasplayerRightTowerMoved;
		this->HasplayerLeftTowerMoved = CopySource.HasplayerLeftTowerMoved;	


		this->HasAIKingCastled = CopySource.HasAIKingCastled;
		this->HasPlayerKingCastled = CopySource.HasPlayerKingCastled;


		this->HasplayerKingMoved = CopySource.HasplayerKingMoved;
		this->HasAIKingMoved = CopySource.HasAIKingMoved;

		this->Turn = CopySource.Turn;
		this->OppositeTurn = CopySource.OppositeTurn;
	}

// Giving the information to BSTBoard needed for implementing a move on the board which is:
	void operator=(const Node& CopySource){

		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				this->chessboard[x][y] = CopySource.chessboard[x][y];
			}
		}		

	this->Turn = CopySource.Turn;

	}
	
	
	
};