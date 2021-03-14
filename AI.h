#pragma once
#include "BST.h"
class AI : public BST
{
public:

	void minimax();
	int evaluationfunction();


	AI(){
		BSTMovegenerator.Turn = "AI";
		BSTMovegenerator.OppositeTurn = "player";
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
	
};

