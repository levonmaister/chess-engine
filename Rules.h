#pragma once
#include "BoardClass.h"


class Rules : public BoardClass
{
public:
	bool IsItOutOfBoard(int x, int y);
	bool IsThereAPiece(int x, int y);
	bool IsItOnEnemyPiece(string move);
	string IdentifyTurn(int x, int y);


	bool IsSquareInDanger(int x, int y);

	// Pawn rules
	bool HasPawnMoved(int oldx, int oldy);
	bool HasPawnReachedEndOfBoard(int newy);

	// Kingcastle Rules
	bool CanKingCastle(string move);
	bool CanKingCastleRightDangerScan(string move);
	bool CanKingCastleLeftDangerScan(string move);
	bool CanKingCastleRightPieceScan(string move);
	bool CanKingCastleLeftPieceScan(string move);

	// Movegenerator special functions
	bool IsKingInDanger();
	bool WillKingBeInDanger(string move,int ID=0);

	// data transfer operator overloading
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
};

