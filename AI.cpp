#include "AI.h"

int AI::evaluationfunction(Node* node){

int AIsum=0;
int playersum=0;

int ValueArray[7]{0,5,3,3,9,1000,1}; // the index is the same as the value of the index number layer 6= pawn pawn= 1 point

// + equals AI and - equals player.

// if true evaluation may be -1000 or 1000
bool FoundAIking=false;
bool Foundplayerking=false;

// adding sums
for(int y=0;y<8;y++){
for(int x=0;x<8;x++){
    // AI
if(node->chessboard[y][x]>0){
    AIsum = AIsum + ValueArray[abs(node->chessboard[y][x])];
}
if(node->chessboard[y][x]<0){
    playersum = playersum + ValueArray[abs(node->chessboard[y][x])];
}

}
}

// evaluation is for how good the board is for AI
int evaluation = AIsum-playersum;

return evaluation;

}

