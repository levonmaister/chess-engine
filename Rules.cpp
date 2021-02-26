#include "Rules.h"

// returns AI player or empty depending on ScanGetValueGeneral
string Rules::IdentifyTurn(int x, int y) 
{
    if (ScanGetValueGeneral(x, y) < 0) { return "player"; }
    else if (ScanGetValueGeneral(x, y) > 0) { return "AI"; }
    else { return "empty"; }
}

// Checks if x and y are larger than 7 or less than 0
bool Rules::IsItOutOfBoard(int x, int y) 
{
    if (x > 7 || x < 0 || y < 0 ||
        y > 7) {
        return true;
    }
    else { return false; }
}

bool Rules::IsThereAPiece(int x, int y) 
{
    // If x y board place is not equal to 0
    if (ScanGetValueGeneral(x, y)!=0) 
    {
        return true;
    }
    else { return false; }
}

// First it checks if there is a piece on the new square
// then it checks if your ID isn't equal to ID of the square you moved to
// does not need to check if square is empty since IsItOnOtherPiece confirms it is on other piece
// then returns true
bool Rules::IsItOnEnemyPiece(string move) 
{
    if (IsThereAPiece(newx(move),newy(move))) 
    {
        if (IdentifyTurn(oldx(move) , oldy(move)) != 
            IdentifyTurn(newx(move) , newy(move))
           ) 
        {
            return true;
        }
        else { return false; }
    }
    else { return false; }
}

bool Rules::IsSquareInDanger(int x, int y) 
{
    // Indicator
    bool SquareIsInDanger = false;
    bool Scan = true;
    int counter = 0;
    string move;
    int vnewx, vnewy;


// Stage 1 Horse Scan
    for (int count = 0; count < 8; count++) 
    {
        move = createmove(x, y, oldx(ScanGetCordinatesHorse(x, y, count)), oldy(ScanGetCordinatesHorse(x, y, count)));
        vnewx = newx(move);
        vnewy = newy(move);

        //Checks that new scan is not out of board with IsOutOfBoard(scangetcordinateshorse)
        if (!IsItOutOfBoard(vnewx, vnewy)) 
        {
        // Check if value is equal to horse and that it is an enemy horse
            if (abs(ScanGetValueHorse(x, y, count)) == 2 && IdentifyTurn(vnewx,vnewy) == OppositeTurn) {return true;}
        }
    }
    
    
// Stage 2 Queen + Tower

    // Scan West
    while (Scan)
    {
        move = createmove(x, y, oldx(ScanGetCordinatesW(x-counter,y)), oldy(ScanGetCordinatesW(x-counter,y)));
        vnewx = newx(move);
        vnewy = newy(move);

        // IsOutOfBoard(ScanWestCordinates)
        if (IsItOutOfBoard(vnewx, vnewy)){Scan = false;}
        // Check if we have landed on a piece

        else if (IsThereAPiece(vnewx, vnewy))
        {
            // Checks if it is equal to queen or tower
            if (abs(ScanGetValueW(x - counter, y)) == 1 ||
                abs(ScanGetValueW(x - counter, y)) == 4)
            {
                // Check if it is the enemy
                if (IdentifyTurn(vnewx, vnewy) == OppositeTurn){return true;}
                // Else if we are on our own piece
                else { Scan = false; }
            }
            else { Scan = false; }

        }
        
        counter++;
    }

    // Reset scan tools
    Scan = true;
    counter = 0;


    // Scan East
    while (Scan)
    {
        move = createmove(x, y, oldx(ScanGetCordinatesE(x + counter, y)), oldy(ScanGetCordinatesE(x + counter, y)));
        vnewx = newx(move);
        vnewy = newy(move);

        // IsOutOfBoard(ScanEastCordinates)
        if (IsItOutOfBoard(vnewx, vnewy)){Scan = false;}

        // Check if we have landed on a piece
        else if (IsThereAPiece(vnewx, vnewy))
        {

            // Checks if it is equal to queen or tower and then 
            if (abs(ScanGetValueE(x + counter, y)) == 1 || abs(ScanGetValueE(x + counter, y)) == 4)
            {
                // Check if it is the enemy
                if (IdentifyTurn(vnewx, vnewy) == OppositeTurn){return true;}
                // Else if we are on our own piece
                else { Scan = false; }
            }
            else { Scan = false; }

        }
        counter++;
    }
    // Reset scan tools
    Scan = true;
    counter = 0;
    // Scan North
    while (Scan)
    {
        move = createmove(x, y, oldx(ScanGetCordinatesN(x, y+counter)), oldy(ScanGetCordinatesN(x, y+counter)));
        vnewx = newx(move);
        vnewy = newy(move);
        // IsOutOfBoard(ScanWestCordinates)
        if (IsItOutOfBoard(vnewx,vnewy)){Scan = false;}

        // Check if we have landed on a piece
        else if (IsThereAPiece(vnewx, vnewy))
        {

            // Checks if it is equal to queen or tower and then 
            if (abs(ScanGetValueN(x, y + counter)) == 1 || abs(ScanGetValueN(x, y + counter)) == 4)
            {   
                // If it is an enemy piece
                if (IdentifyTurn(vnewx  ,  vnewy) == OppositeTurn){return true;}
                // Else if we are on our own piece
                else { Scan = false; }
            }
                // Else if we are on our own piece
                else { Scan = false; }
        }
        counter++;
    }
    // Reset scan tools
    Scan = true;
    counter = 0;


    // Scan South
    while (Scan)
    {
        move = createmove(x, y, oldx(ScanGetCordinatesS(x, y-counter)), oldy(ScanGetCordinatesS(x , y-counter)));
        vnewx = newx(move);
        vnewy = newy(move);

        // IsOutOfBoard(ScanWestCordinates)
        if (IsItOutOfBoard(vnewx, vnewy))
        {
            Scan = false;
        }
        // Check if we have landed on a piece
        else if (IsThereAPiece(vnewx, vnewy))
        {
            // Checks if it is equal to queen or tower and then 
            if (abs(ScanGetValueS(x, y - counter)) == 1 || abs(ScanGetValueS(x, y - counter)) == 4)
            {
                // If it is an enemy piece
                if(IdentifyTurn(vnewx,vnewy) == OppositeTurn){return true;}
                // Else if we are on our own piece
                else { Scan = false; }
            }
            // Else if we are on our own piece
            else { Scan = false; }
        }
        counter++;
    }
    Scan = true;
    counter = 0;

// Stage 3 Queen + Bishop

    // Scan North West
    while (Scan)
    {
        move = createmove(x, y, oldx(ScanGetCordinatesNW(x - counter, y+counter)), oldy(ScanGetCordinatesNW(x - counter, y+counter)));
        vnewx = newx(move);
        vnewy = newy(move);

        // IsOutOfBoard(ScanNorthWestCordinates)
        if (IsItOutOfBoard(vnewx, vnewy)){Scan = false;}

        // Check if we have landed on a piece
        else if (IsThereAPiece(vnewx, vnewy))
        {
            // Checks if it is equal to queen or tower and then 
            // If it is an enemy piece
            if (abs(ScanGetValueNW(x - counter, y + counter)) == 3 || abs(ScanGetValueNW(x - counter, y + counter)) == 4)
            {
                if(IdentifyTurn(vnewx,vnewy) == OppositeTurn){return true;}
                // Else if we are on our own piece
                else { Scan = false; }
            }
            // Else if we are on our own piece
            else { Scan = false; }
        }
        counter++;
    }
    // Reset scan tools
    Scan = true;
    counter = 0;

    // Scan North East
    while (Scan)
    {
        move = createmove(x, y, oldx(ScanGetCordinatesNE(x + counter, y+counter)), oldy(ScanGetCordinatesNE(x + counter, y+counter)));
        vnewx = newx(move);
        vnewy = newy(move);
        // IsOutOfBoard(ScanWestCordinates)
        if (IsItOutOfBoard(vnewx,vnewy)){Scan = false;}

        // Check if we have landed on a piece
        else if (IsThereAPiece(vnewx, vnewy))
        {
            // Checks if it is equal to queen or tower and then 
           
            if (abs(ScanGetValueNE(x + counter, y + counter)) == 3 || abs(ScanGetValueNE(x + counter, y + counter)) == 4)
            {
                // If it is an enemy piece
                if(IdentifyTurn(vnewx,vnewy) == OppositeTurn){return true;}
                // Else if we are on our own piece
                else { Scan = false; }
            }
            // Else if we are on our own piece
            else { Scan = false; }

        }
        counter++;
    }
    // Reset scan tools
    Scan = true;
    counter = 0;

    // Scan South West

    while (Scan)
    {
        move = createmove(x, y, oldx(ScanGetCordinatesSW(x - counter, y-counter)), oldy(ScanGetCordinatesSW(x - counter, y-counter)));
        vnewx = newx(move);
        vnewy = newy(move);

        // IsOutOfBoard(ScanWestCordinates)
        if (IsItOutOfBoard(vnewx, vnewy)){Scan = false;}

        // Check if we have landed on a piece
        else if (IsThereAPiece(vnewx,vnewy))
        {
            // Checks if it is equal to queen or tower and then 
            // If it is an enemy piece
            if (abs(ScanGetValueSW(x - counter, y - counter)) == 3 || abs(ScanGetValueSW(x - counter, y - counter)) == 4)
            {
                if (IdentifyTurn(vnewx,vnewy) == OppositeTurn) {return true;}
                // Else if we are on our own piece
                else { Scan = false; }
            }
            // Else if we are on our own piece
            else { Scan = false; }
        }
        counter++;
    }
    // Reset scan tools
    Scan = true;
    counter = 0;


    // Scan South East
    while (Scan)
    {
        move = createmove(x, y, oldx(ScanGetCordinatesSE(x - counter, y-counter)), oldy(ScanGetCordinatesSE(x - counter, y-counter)));
        vnewx = newx(move);
        vnewy = newy(move);

        // IsOutOfBoard(ScanWestCordinates)
        if (IsItOutOfBoard(vnewx, vnewy)){Scan = false;}
        // Check if we have landed on a piece
        else if (IsThereAPiece(vnewx, vnewy))
        {
            // Checks if it is equal to queen or tower and then 
            // If it is an enemy piece
            if (abs(ScanGetValueSE(x + counter, y - counter)) == 3 || abs(ScanGetValueSE(x + counter, y - counter)) == 4)
            {
                if(IdentifyTurn(vnewx,vnewy) == OppositeTurn){return true;}
                
                // Else if we are on our own piece
                else { Scan = false; }
            }
            // Else if we are on our own piece
            else { Scan = false; }
        }
        counter++;
    }

    counter = 0;
// Stage 4 Pawn

    // YOU DONT NEED COUNTER WHEN DEALING WITH PAWNS

       // Right Pawn search for player squares and threats from AI
    if (Turn == "player") {
        if (!IsItOutOfBoard(oldx(ScanGetCordinatesNE(x + counter, y + counter)), oldy(ScanGetCordinatesNE(x + counter, y + counter))))
        {


            if (abs(ScanGetValueNE(x + counter, y + counter)) == 6)
            {
                if (IdentifyTurn(oldx(ScanGetCordinatesNE(x + counter, y + counter)), oldy(ScanGetCordinatesNE(x + counter, y + counter))) == "AI")
                {
                   return true;
                }
            }
           
        }

        // Left pawn search for AI threats 
        if (!IsItOutOfBoard(oldx(ScanGetCordinatesNW(x - counter, y + counter)), oldy(ScanGetCordinatesNW(x - counter, y + counter))))
        {


            if (abs(ScanGetValueNW(x - counter, y + counter)) == 6)
            {
                if (IdentifyTurn(oldx(ScanGetCordinatesNW(x - counter, y + counter)), oldy(ScanGetCordinatesNW(x - counter, y + counter))) == "AI")
                {
                   return true;
                }
            }
        }

    }

    // Searching for threats on AI
    else {
        // Left pawn search for player threats
        if (!IsItOutOfBoard(oldx(ScanGetCordinatesSW(x - counter, y - counter)), oldy(ScanGetCordinatesSW(x - counter, y - counter))))
        {


            if (abs(ScanGetValueSW(x - counter, y + counter)) == 6)
            {
                if (IdentifyTurn(oldx(ScanGetCordinatesSW(x - counter, y - counter)), oldy(ScanGetCordinatesSW(x - counter, y - counter))) == "player")
                {
                        return true;
                }
            }
        }

        // Right pawn search for player threats
        if (!IsItOutOfBoard(oldx(ScanGetCordinatesSE(x + counter, y - counter)), oldy(ScanGetCordinatesSE(x + counter, y - counter))))
        {


            if (abs(ScanGetValueSW(x + counter, y + counter)) == 6)
            {
                if (IdentifyTurn(oldx(ScanGetCordinatesSE(x + counter, y - counter)), oldy(ScanGetCordinatesSE(x + counter, y - counter))) == "player")
                {
                          return true;
                }
            }
        }
    }

    // ADD KING SEARCH
    // king search added
    if(!IsItOutOfBoard(oldx(ScanGetCordinatesN(x,y)),oldy(ScanGetCordinatesN(x,y)) ) && IsThereAPiece(oldx(ScanGetCordinatesN(x,y)),oldy(ScanGetCordinatesN(x,y)))){
        if (IdentifyTurn(oldx(ScanGetCordinatesN(x, y)), oldy(ScanGetCordinatesN(x, y))) == OppositeTurn) {
            if (abs(ScanGetValueN(x, y)) == 5) { return true;}
       }
    }

    if (!IsItOutOfBoard(oldx(ScanGetCordinatesS(x, y)), oldy(ScanGetCordinatesS(x, y))) && IsThereAPiece(oldx(ScanGetCordinatesS(x, y)), oldy(ScanGetCordinatesS(x, y)))) {
        if (IdentifyTurn(oldx(ScanGetCordinatesS(x, y)), oldy(ScanGetCordinatesS(x, y))) == OppositeTurn) {
            if (abs(ScanGetValueS(x, y)) == 5) { return true; }
        }
    }

    if (!IsItOutOfBoard(oldx(ScanGetCordinatesE(x, y)), oldy(ScanGetCordinatesE(x, y))) && IsThereAPiece(oldx(ScanGetCordinatesE(x, y)), oldy(ScanGetCordinatesE(x, y)))) {
        if (IdentifyTurn(oldx(ScanGetCordinatesE(x, y)), oldy(ScanGetCordinatesE(x, y))) == OppositeTurn) {
            if (abs(ScanGetValueE(x, y)) == 5) { return true; }
        }
    }

    if (!IsItOutOfBoard(oldx(ScanGetCordinatesW(x, y)), oldy(ScanGetCordinatesW(x, y))) && IsThereAPiece(oldx(ScanGetCordinatesW(x, y)), oldy(ScanGetCordinatesW(x, y)))) {
        if (IdentifyTurn(oldx(ScanGetCordinatesW(x, y)), oldy(ScanGetCordinatesW(x, y))) == OppositeTurn) {
            if (abs(ScanGetValueW(x, y)) == 5) { return true; }
        }
    }

    if (!IsItOutOfBoard(oldx(ScanGetCordinatesNE(x, y)), oldy(ScanGetCordinatesNE(x, y))) && IsThereAPiece(oldx(ScanGetCordinatesNE(x, y)), oldy(ScanGetCordinatesNE(x, y)))) {
        if (IdentifyTurn(oldx(ScanGetCordinatesNE(x, y)), oldy(ScanGetCordinatesNE(x, y))) == OppositeTurn) {
            if (abs(ScanGetValueNE(x, y)) == 5) { return true; }
        }
    }

    if (!IsItOutOfBoard(oldx(ScanGetCordinatesNW(x, y)), oldy(ScanGetCordinatesNW(x, y))) && IsThereAPiece(oldx(ScanGetCordinatesNW(x, y)), oldy(ScanGetCordinatesNW(x, y)))) {
        if (IdentifyTurn(oldx(ScanGetCordinatesNW(x, y)), oldy(ScanGetCordinatesNW(x, y))) == OppositeTurn) {
            if (abs(ScanGetValueNW(x, y)) == 5) { return true; }
        }
    }

    if (!IsItOutOfBoard(oldx(ScanGetCordinatesSE(x, y)), oldy(ScanGetCordinatesSE(x, y))) && IsThereAPiece(oldx(ScanGetCordinatesSE(x, y)), oldy(ScanGetCordinatesSE(x, y)))) {
        if (IdentifyTurn(oldx(ScanGetCordinatesSE(x, y)), oldy(ScanGetCordinatesSE(x, y))) == OppositeTurn) {
            if (abs(ScanGetValueSE(x, y)) == 5) { return true; }
        }
    }

    if (!IsItOutOfBoard(oldx(ScanGetCordinatesSW(x, y)), oldy(ScanGetCordinatesSW(x, y))) && IsThereAPiece(oldx(ScanGetCordinatesSW(x, y)), oldy(ScanGetCordinatesSW(x, y)))) {
        if (IdentifyTurn(oldx(ScanGetCordinatesSW(x, y)), oldy(ScanGetCordinatesSW(x, y))) == OppositeTurn) {
            if (abs(ScanGetValueSW(x, y)) == 5) { return true; }
        }
    }
    // If nothing was hit
   
     return false;
}



// Opening moves for pawns
bool Rules::HasPawnMoved(int oldx, int oldy) 
{
    string ID = IdentifyTurn(oldx, oldy);

    if (ID == "player") 
    {   
        if (oldy == 1) { return false; }
        else { return true; }
    }
    else if (ID == "AI") 
    {
        if (oldy == 6) { return false; }
        else { return true; }
    }
    else { cout << "something went wrong we arent dealing with a piece at all HasPawnMoved true returned" << endl;}
}

// takes in y and checks if pawn has reached end of board
// you decide whether you want to use it for newy or current y
bool Rules::HasPawnReachedEndOfBoard(int y) 
{
    if (y == 0 || y == 7) { return true; }
    else { return true; }
}


bool Rules::CanKingCastle(string move)
{

    SetHasKingsMovedYet();
    SetHasTowersMovedYet();

    // For AI
    
    // Determine type of castle
    bool RightCastle=false;
    if (newx(move) == 7) { RightCastle = true; }

    // Determine turn
    bool AITurn = false;
    if (oldy(move) == 7) { AITurn = true; }

    // If we've already castled before then return false
    if (AITurn && HasAIKingCastled == true) { return false; }
    if (!AITurn && HasPlayerKingCastled == true) { return false; }
    
    // Right castle for both AI and player checking for dangers and pieces in the way
    if (RightCastle) {
    
        if (CanKingCastleRightDangerScan(move) && CanKingCastleRightPieceScan(move)) { return true; }
        else { return false; }
    }

    // Left Castle for both AI and player
    if (!RightCastle) {
    
        if (CanKingCastleLeftDangerScan(move) && CanKingCastleLeftPieceScan(move)) { return true; }
        else {return false;}

    }

  

    
    return true;
}

// Safe way for king to castle function checkers 

// Checks for squares in danger along the runway
    bool Rules::CanKingCastleRightDangerScan(string move) 
    {
        // Scannig is square in danger right including the king square
        for (int z = 0; z < 4; z++) 
        {
            if (IsSquareInDanger(z + 4, oldy(move))) {
               return false;
            }
        }
        return true;

    }
    bool Rules::CanKingCastleLeftDangerScan(string move)
    {
        // Scannig is square in danger left includig the king square
        for (int z = 0; z < 5; z++)
        {
            if (IsSquareInDanger(4-z, oldy(move))) {
              return false;
            }
        }
        return true;

    }

// Checks for pieces in the way along the driveway
    bool Rules::CanKingCastleRightPieceScan(string move) {
    
    
        // Scannig is there a piece on the square not including tower and king square
        for (int z = 1; z < 3; z++)
        {
            if (IsThereAPiece(4 + z, oldy(move))) {
               return false;
            }
        }
        return true;
    
    }
    bool Rules::CanKingCastleLeftPieceScan(string move) {
        // Scannig is there a piece on the square not including tower and king square
        for (int z = 1; z < 4; z++)
        {
            if (IsThereAPiece(4 - z, oldy(move))) {
                return false;
            }
        }
        return true;
    
    
    }


    bool Rules::IsKingInDanger()
    {
    for(int x=0;x<8;x++){
        for (int y = 0; y < 8; y++) {
            if (abs(ScanGetValueGeneral(x,y)) == 5 && IdentifyTurn(x,y) == Turn) { 
                if(IsSquareInDanger(x,y)){return true;}
                 }
        }
    }
    return false;
    }

    // ID needed for pawns becoming queens used for movegenerator
    bool Rules::WillKingBeInDanger(string move, int ID){
        
        Rules implementedboard;

        // data transfer    OBS WE MuST DO THE OTHER VARIABLES IN DATA TRANSFER
        implementedboard.Turn = IdentifyTurn(oldx(move), oldy(move));
        if (implementedboard.Turn == "player") { implementedboard.OppositeTurn = "AI"; }
        else { implementedboard.OppositeTurn = "player"; }


        // SETUP THE NEW BOARD

        // copy board
        for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            implementedboard.chessboard[y][x] = chessboard[y][x];
        }
        }

        // Implement move on new board

        // IF regular move
        if (ID == 0) {

            // implement move on local chess board
            implementedboard.chessboard[newy(move)][newx(move)] = chessboard[oldy(move)][oldx(move)];
            implementedboard.chessboard[oldy(move)][oldx(move)] = 0;
        }
        // if pawn reaches end of board
        else {
            // implement move on local chess board
            implementedboard.chessboard[newy(move)][newx(move)] = ID;
            implementedboard.chessboard[oldy(move)][oldx(move)] = 0;
        }
        

        


        // Core program
        if (implementedboard.IsKingInDanger()) { return true; }
        else { return false; }





    }

