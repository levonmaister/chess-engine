#include"Node.h";
#include"BST.h"





// for the root data transfer when we dont want a regular node
void Node::operator=(const BST& CopySource) {

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

    this->Turn = "AI";
    this->depth = 0;


}

// Node to movegen
void Node::operator =(const Movegenerator& CopySource) {
    // New kingcastle variables for the root board
    this->HasAIRightTowerMoved = CopySource.HasAIRightTowerMoved;
    this->HasAILeftTowerMoved = CopySource.HasAIRightTowerMoved;
    this->HasplayerRightTowerMoved = CopySource.HasplayerRightTowerMoved;
    this->HasplayerLeftTowerMoved = CopySource.HasplayerLeftTowerMoved;


    this->HasAIKingCastled = CopySource.HasAIKingCastled;
    this->HasPlayerKingCastled = CopySource.HasPlayerKingCastled;


    this->HasplayerKingMoved = CopySource.HasplayerKingMoved;
    this->HasAIKingMoved = CopySource.HasAIKingMoved;

    // The movelist that BSTmovegenerator generated
    for (int x = 0; x < CopySource.movelist.size(); x++) {
        this->Nmovelist.push_back(CopySource.movelist[x]);
    }

}

//Transfering data from BSTBoard to get the implemented board
void Node::operator =(const BoardClass& CopySource) {

    // Board

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            this->chessboard[x][y] = CopySource.chessboard[x][y];
        }
    }
}


// For transfering data from root to children
void Node::operator =(const Node& ptr) {

    // Chessboard
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            this->chessboard[x][y] = ptr.chessboard[x][y];
        }
    }

    // KingCastle variables
    this->HasAIRightTowerMoved = ptr.HasAIRightTowerMoved;
    this->HasAILeftTowerMoved = ptr.HasAIRightTowerMoved;
    this->HasplayerRightTowerMoved = ptr.HasplayerRightTowerMoved;
    this->HasplayerLeftTowerMoved = ptr.HasplayerLeftTowerMoved;


    this->HasAIKingCastled = ptr.HasAIKingCastled;
    this->HasPlayerKingCastled = ptr.HasPlayerKingCastled;


    this->HasplayerKingMoved = ptr.HasplayerKingMoved;
    this->HasAIKingMoved = ptr.HasAIKingMoved;

    // TURN
    if (ptr.Turn == "AI") {
        this->Turn = "player";
    }
    else {
        this->Turn = "AI";
    }

    // DEPTH
    this->depth = ptr.depth + 1;



}

// the cosntructor for the root
Node::Node(BST* BST){

// Data transfer
*this = *BST;


    // Data transfer from node to bstmovegen
    BST->BSTMovegenerator = *this;

    // Generate moves
    BST->BSTMovegenerator.GenerateMoves();

    // Transfer data from movegen to node
    *this = BST->BSTMovegenerator;


// Create new nodes for the root
for(int x=0;x<Nmovelist.size();x++){
    NodePtr.push_back(new Node(this,BST,Nmovelist[x]));
}
}

Node::Node(Node* root, BST* BST, string move){

// What to do if  this = the root SOLVE LATER
*(this) = *root;


// Implement move on board through the BSTBoard object

        // Transfer from node to BSTBoard data
        BST->BSTBoard = *(this);


// Finding the ID of the move
int moveID = BST->BSTBoard.ImplementMoveFindID(move);
//Implementing the move
BST->BSTBoard.ImplementMoveOnBoard(move, moveID);

        // Getting back the implemented board
        *(this) = BST->BSTBoard;


//Generating the movelist

// checking for current depth
if(depth<3){
    // Data transfer from node to bstmovegen
    BST->BSTMovegenerator = *(this);

// Generate moves
BST->BSTMovegenerator.GenerateMoves();

    // Transfer data from movegen to node
    *(this) = BST->BSTMovegenerator;
}

// Create the new nodes out of the movelist we have

for(int x=0;x<Nmovelist.size();x++){
    NodePtr.push_back(new Node(this,BST,Nmovelist[x]));
}


}

Node::~Node() {

    for (int x = 0; x < NodePtr.size(); x++) {
        delete NodePtr[x];
    }
}