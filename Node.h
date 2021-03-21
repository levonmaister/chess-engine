#pragma once
#include<vector>
#include<string>
class BST;
class Movegenerator;
class BoardClass;

using namespace std;


class Node{
public:
string Turn;
int depth;
// King castle variables
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

	bool HasPlayerKingCastled = false;
	bool HasAIKingCastled = false;

int chessboard[8][8];

vector<Node*> NodePtr;
vector<string> Nmovelist;
int evaluation=0;



// For transfering data from root to children
void operator =(const Node& ptr);

//Transfering data from BSTBoard to get the implemented board
void operator =(const BoardClass& CopySource);

// Node to movegen
void operator =(const Movegenerator& CopySource);

// for the root data transfer when we dont want a regular node
void operator=(const BST& CopySource);


Node(BST* BST);
Node(Node* root, BST* BST, string move);
~Node();



};







