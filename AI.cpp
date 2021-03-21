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

int AI::max(int max1, int max2) {
    if (max1 > max2) {
        return max1;
    }
    else{
        // doesnt matter if max2 = max1 then we just return one of them, in this case max2
        return max2;
    }
}

int AI::mini(int min1, int min2) {
    if (min1 < min2) {
        return min1;
    }
    else {
        // doesnt matter if max2 = max1 then we just return one of them, in this case min2
        return min2;
    }
}

int AI::minimax(Node* nodeptr, bool maximizingplayer)
{
    if (nodeptr->NodePtr.size() == 0) {
        nodeptr->evaluation = evaluationfunction(nodeptr);
        return nodeptr->evaluation;
    }

    if (maximizingplayer) {
        int maxevaluation = -4000;
        for (int x = 0; x < nodeptr->NodePtr.size(); x++) {
            nodeptr->NodePtr[x]->evaluation = minimax(nodeptr->NodePtr[x], false);
            maxevaluation = max(nodeptr->NodePtr[x]->evaluation, maxevaluation);
        }
        return maxevaluation;
    }

    else {
        int minimumevaluation = 4000;
        for (int x = 0; x < nodeptr->NodePtr.size(); x++) {
            nodeptr->NodePtr[x]->evaluation = minimax(nodeptr->NodePtr[x], true);
            minimumevaluation = min(nodeptr->NodePtr[x]->evaluation, minimumevaluation);
        }
        return minimumevaluation;
    }

}


string AI::GetMove() {
    cout << "creating tree " << endl;
    CreateTree();
    cout << "tree created " << endl;

    cout << "calling minimax" << endl;
    int BestEvaluation = minimax(rootptr,true);
    cout << "minimax called best evaluation = " << BestEvaluation << endl;
    // Finding out which node it was that returned the best evaluation
    vector<string> bestmoves;
    for (int x = 0; x < rootptr->NodePtr.size(); x++) {
        if (BestEvaluation == rootptr->NodePtr[x]->evaluation) {
            bestmoves.push_back(rootptr->Nmovelist[x]);
        }
    }
    cout << "deleting tree " << endl;
    DeleteTree();
    cout << "tree deleted " << endl;
    return bestmoves[RandomNumberGen(bestmoves.size())];

}
