#pragma once
#include"Rules.h"
#include"Node.h"

class Movegenerator : public Rules
{
public:
	vector <string> movelist;
	string getMove(int count);
	int getLength();
	void EmptyList();
	void GenerateMoves();
	// Put in the cordinates of a piece and then it updates move list with the possible moves for that piece in that position
	void PieceSearch(int cx, int cy,int ID=100);

	bool HaveTurnRanOutOfMoves();

	// graphics things and ui debugging
	void PrintMoves() {

		for (int x = 0; x < getLength(); x++) {
			cout << movelist[x] << endl;
		}


	}


	
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


void operator =(const Node& CopySource){
//Board
	for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				this->chessboard[x][y] = CopySource.chessboard[x][y];
			}
		}
//King castle variables
		this->HasAIRightTowerMoved = CopySource.HasAIRightTowerMoved;
		this->HasAILeftTowerMoved = CopySource.HasAIRightTowerMoved;
		this->HasplayerRightTowerMoved = CopySource.HasplayerRightTowerMoved;
		this->HasplayerLeftTowerMoved = CopySource.HasplayerLeftTowerMoved;


		this->HasAIKingCastled = CopySource.HasAIKingCastled;
		this->HasPlayerKingCastled = CopySource.HasPlayerKingCastled;


		this->HasplayerKingMoved = CopySource.HasplayerKingMoved;
		this->HasAIKingMoved = CopySource.HasAIKingMoved;

		this->Turn = CopySource.Turn;
		
		// Transfering opposite turn
		if(CopySource.Turn=="AI"){this->OppositeTurn="player";}
		else{this->OppositeTurn="AI";}
}

};


