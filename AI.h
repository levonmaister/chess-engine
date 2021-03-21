#pragma once
#include "BST.h"
class AI : public BST
{
public:

	int minimax(Node* nodeptr,bool maximizingPlayer);
	int evaluationfunction(Node* node);
	int max(int max1, int max2);
	int mini(int min1, int min2);

	// creates tree and then
	// Implements minimax to find the move
	string GetMove();

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

