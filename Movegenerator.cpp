#include "Movegenerator.h"

// gives the number of elements in the array starting from 1->
int Movegenerator::getLength() { return movelist.size(); }

// empties list data
void Movegenerator::EmptyList() { vector<string>().swap(movelist); }

// returns a move from move list at position count
string Movegenerator::getMove(int count) { return movelist[count]; }

void Movegenerator::GenerateMoves()
{
	// Makes sure list is 0
	EmptyList();

	// Scanning through the whole board
	for (int cx = 0; cx < 8; cx++) 
	{
		for (int cy = 0; cy < 8; cy++) 
		{
			if (IdentifyTurn(cx, cy) == Turn) {

				PieceSearch(cx, cy);
			}
		}
	}
}


void Movegenerator::PieceSearch(int cx, int cy, int ID)
{
	// SCAN TOOLS
	bool Scan = true;
	int scancounter = 0;
	string move;
	int vnewx, vnewy;


	if (ID == 100) {
		ID = abs(chessboard[cy][cx]);
	}
	switch (ID) {
		// Tower
	case 1:
		// North Scan
		while (Scan) {

			// Scan the move and cordinates
			move = createmove(cx, cy, oldx(ScanGetCordinatesN(cx, cy + scancounter)), oldy(ScanGetCordinatesN(cx, cy + scancounter)));
			vnewx = newx(move), vnewy = newy(move);


			// Out of board check
			if (IsItOutOfBoard(vnewx, vnewy)) {
				Scan = false;
			}
			// Piece in the way check
			else if (IsThereAPiece(vnewx, vnewy)) {

				Scan = false;
				// Add move if it is enemy
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			// Add move if it is not out of board and nothing is in the way
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				scancounter++;
			}

		}

		Scan = true;
		scancounter = 0;


		// Scanning south
		while (Scan) {

			// Scan the move and cordinates
			move = createmove(cx, cy, oldx(ScanGetCordinatesS(cx, cy - scancounter)), oldy(ScanGetCordinatesS(cx, cy - scancounter)));
			vnewx = newx(move), vnewy = newy(move);

			// Out of board check
			if (IsItOutOfBoard(vnewx, vnewy)) {
				Scan = false;
			}
			// Piece in the way check
			else if (IsThereAPiece(vnewx, vnewy)) {

				Scan = false;
				// Add move if it is enemy
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					// Check king wont be in danger

					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			// Add move if it is not out of board and nothing is in the way
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				scancounter++;
			}

		}
		Scan = true;
		scancounter = 0;

		// East
		while (Scan) {

			// Scan the moves and cordinates
			move = createmove(cx, cy, oldx(ScanGetCordinatesE(cx + scancounter, cy)), oldy(ScanGetCordinatesE(cx + scancounter, cy)));
			vnewx = newx(move), vnewy = newy(move);

			// Out of board check
			if (IsItOutOfBoard(vnewx, vnewy)) {
				Scan = false;
			}
			// Piece in the way check
			else if (IsThereAPiece(vnewx, vnewy)) {

				Scan = false;
				// Add move if it is enemy
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			// Add move if it is not out of board and nothing is in the way
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				scancounter++;
			}

		}

		Scan = true;
		scancounter = 0;

		// Scanning west
		while (Scan) {

			// Scan move and cordinates
			move = createmove(cx, cy, oldx(ScanGetCordinatesW(cx - scancounter, cy)), oldy(ScanGetCordinatesW(cx - scancounter, cy)));
			vnewx = newx(move), vnewy = newy(move);

			// Out of board check
			if (IsItOutOfBoard(vnewx, vnewy)) {
				Scan = false;
			}
			// Piece in the way check
			else if (IsThereAPiece(vnewx, vnewy)) {

				Scan = false;
				// Add move if it is enemy
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			// Add move if it is not out of board and nothing is in the way
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				scancounter++;
			}

		}
		break;
		// Horse
	case 2:
		for (int x = 0; x < 8; x++) {
			move = createmove(cx, cy, oldx(ScanGetCordinatesHorse(cx, cy, x)), oldy(ScanGetCordinatesHorse(cx, cy, x)));
			// Check if scan is out of board
			if (!IsItOutOfBoard(newx(move), newy(move))) {
				// Check if there is a piece
				if (IsThereAPiece(newx(move), newy(move))) {
					// check if it is an enemy that can be eaten
					if (IdentifyTurn(newx(move), newy(move)) == OppositeTurn) {
						if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
					}
				}
				else {
					// If there is not a piece
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
		}
		break;
		// Bishop
	case 3:

		// NE scan
		Scan = true;
		scancounter = 0;
		while (Scan) {

			// Scan the move and cordinates
			move = createmove(cx, cy, oldx(ScanGetCordinatesNE(cx+scancounter, cy + scancounter)), oldy(ScanGetCordinatesNE(cx+scancounter, cy + scancounter)));
			vnewx = newx(move), vnewy = newy(move);


			// Out of board check
			if (IsItOutOfBoard(vnewx, vnewy)) {
				Scan = false;
			}
			// Piece in the way check
			else if (IsThereAPiece(vnewx, vnewy)) {

				Scan = false;
				// Add move if it is enemy
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			// Add move if it is not out of board and nothing is in the way
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				scancounter++;
			}

		}
		Scan = true;
		scancounter = 0;

		// NW scan
		while (Scan) {

			// Scan the move and cordinates
			move = createmove(cx, cy, oldx(ScanGetCordinatesNW(cx-scancounter, cy + scancounter)), oldy(ScanGetCordinatesNW(cx-scancounter, cy + scancounter)));
			vnewx = newx(move), vnewy = newy(move);


			// Out of board check
			if (IsItOutOfBoard(vnewx, vnewy)) {
				Scan = false;
			}
			// Piece in the way check
			else if (IsThereAPiece(vnewx, vnewy)) {

				Scan = false;
				// Add move if it is enemy
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			// Add move if it is not out of board and nothing is in the way
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				scancounter++;
			}

		}

		Scan = true;
		scancounter = 0;

		// SE
		while (Scan) {

			// Scan the move and cordinates
			move = createmove(cx, cy, oldx(ScanGetCordinatesSE(cx+scancounter, cy - scancounter)), oldy(ScanGetCordinatesSE(cx+scancounter, cy - scancounter)));
			vnewx = newx(move), vnewy = newy(move);


			// Out of board check
			if (IsItOutOfBoard(vnewx, vnewy)) {
				Scan = false;
			}
			// Piece in the way check
			else if (IsThereAPiece(vnewx, vnewy)) {

				Scan = false;
				// Add move if it is enemy
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			// Add move if it is not out of board and nothing is in the way
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				scancounter++;
			}

		}
		Scan = true;
		scancounter = 0;

		// SW
		while (Scan) {

			// Scan the move and cordinates
			move = createmove(cx, cy, oldx(ScanGetCordinatesSW(cx-scancounter, cy - scancounter)), oldy(ScanGetCordinatesSW(cx-scancounter, cy - scancounter)));
			vnewx = newx(move), vnewy = newy(move);


			// Out of board check
			if (IsItOutOfBoard(vnewx, vnewy)) {
				Scan = false;
			}
			// Piece in the way check
			else if (IsThereAPiece(vnewx, vnewy)) {

				Scan = false;
				// Add move if it is enemy
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			// Add move if it is not out of board and nothing is in the way
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				scancounter++;
			}

		}
		break;
		// Queen = Bishop + Tower
	case 4:
		PieceSearch(cx, cy, 3);
		PieceSearch(cx, cy, 1);
		break;
		// King = pregenerated moves
	case 5:
		// North
		move = createmove(cx, cy, oldx(ScanGetCordinatesN(cx, cy)), oldy(ScanGetCordinatesN(cx, cy)));
		vnewx = newx(move);
		vnewy = newy(move);


		if (!IsItOutOfBoard(vnewx, vnewy)) {
			if (IsThereAPiece(vnewx, vnewy)) {
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
			}
		}

		// South
		move = createmove(cx, cy, oldx(ScanGetCordinatesS(cx, cy)), oldy(ScanGetCordinatesS(cx, cy)));
		vnewx = newx(move);
		vnewy = newy(move);


		if (!IsItOutOfBoard(vnewx, vnewy)) {
			if (IsThereAPiece(vnewx, vnewy)) {
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
			}
		}

		// West
		move = createmove(cx, cy, oldx(ScanGetCordinatesW(cx, cy)), oldy(ScanGetCordinatesW(cx, cy)));
		vnewx = newx(move);
		vnewy = newy(move);


		if (!IsItOutOfBoard(vnewx, vnewy)) {
			if (IsThereAPiece(vnewx, vnewy)) {
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
			}
		}

		// East
		move = createmove(cx, cy, oldx(ScanGetCordinatesE(cx, cy)), oldy(ScanGetCordinatesE(cx, cy)));
		vnewx = newx(move);
		vnewy = newy(move);


		if (!IsItOutOfBoard(vnewx, vnewy)) {
			if (IsThereAPiece(vnewx, vnewy)) {
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
			}
		}

		// North East
		move = createmove(cx, cy, oldx(ScanGetCordinatesNE(cx, cy)), oldy(ScanGetCordinatesNE(cx, cy)));
		vnewx = newx(move);
		vnewy = newy(move);


		if (!IsItOutOfBoard(vnewx, vnewy)) {
			if (IsThereAPiece(vnewx, vnewy)) {
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
			}
		}

		// North West
		move = createmove(cx, cy, oldx(ScanGetCordinatesNW(cx, cy)), oldy(ScanGetCordinatesNW(cx, cy)));
		vnewx = newx(move);
		vnewy = newy(move);


		if (!IsItOutOfBoard(vnewx, vnewy)) {
			if (IsThereAPiece(vnewx, vnewy)) {
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
			}
		}

		// South East
		move = createmove(cx, cy, oldx(ScanGetCordinatesSE(cx, cy)), oldy(ScanGetCordinatesSE(cx, cy)));
		vnewx = newx(move);
		vnewy = newy(move);


		if (!IsItOutOfBoard(vnewx, vnewy)) {
			if (IsThereAPiece(vnewx, vnewy)) {
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
			}
		}


		// South West
		move = createmove(cx, cy, oldx(ScanGetCordinatesSW(cx, cy)), oldy(ScanGetCordinatesSW(cx, cy)));
		vnewx = newx(move);
		vnewy = newy(move);


		if (!IsItOutOfBoard(vnewx, vnewy)) {
			if (IsThereAPiece(vnewx, vnewy)) {
				if (IdentifyTurn(vnewx, vnewy) == OppositeTurn) {
					if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
				}
			}
			else {
				if (!WillKingBeInDanger(move)) { movelist.push_back(move); }
			}
		}




		// KING CASTLE
		
		// 4-7 5-0 x axis
		move = createmove(4, 0, 7, 0);
		if (CanKingCastle(move)) { movelist.push_back(move); }
		move = createmove(4, 0, 0, 0);
		if (CanKingCastle(move)) { movelist.push_back(move); }
		move = createmove(4, 7, 7, 7);
		if (CanKingCastle(move)) { movelist.push_back(move); }
		move = createmove(4, 7, 0, 7);
		if (CanKingCastle(move)) { movelist.push_back(move); }


		break;
		// Pawn, different depending on turn and can become queen
	case 6:
		if (Turn == "player") {

			// Check if we can jump forward 2 times 
			if (!HasPawnMoved(cx, cy)) {
				if (!IsThereAPiece(cx, cy + 2) && !IsThereAPiece(cx,cy+1)) {
					if (!WillKingBeInDanger(createmove(cx, cy, cx, cy + 2))) {
						movelist.push_back(createmove(cx, cy, cx, cy + 2));
					}
				}
			}

			// check if we can go on forward
			if (!IsThereAPiece(cx, cy + 1)) {
				if (!WillKingBeInDanger(createmove(cx, cy, cx, cy + 1))) {
					movelist.push_back(createmove(cx, cy, cx, cy + 1));
				}
			}

			// Check if we can eat right
			// Check we arent eating out of the board
			if (!IsItOutOfBoard(cx + 1, cy + 1)) {
				if (IsThereAPiece(cx + 1, cy + 1)) {
					if (IdentifyTurn(cx + 1, cy + 1) == "AI") {
						if (!WillKingBeInDanger(createmove(cx, cy, cx + 1, cy + 1))) {
							movelist.push_back(createmove(cx, cy, cx + 1, cy + 1));
						}
					}

				}

			}

			// Check if we can left
			// Check we arent eating out of the board
			if (!IsItOutOfBoard(cx - 1, cy + 1)) {
				if (IsThereAPiece(cx - 1, cy + 1)) {
					if (IdentifyTurn(cx - 1, cy + 1) == "AI") {
						if (!WillKingBeInDanger(createmove(cx, cy, cx - 1, cy + 1))) {
							movelist.push_back(createmove(cx, cy, cx - 1, cy + 1));
						}
					}

				}

			}
		}



		// AI Pawn search
		//AIAIAIAIAIAIAIAIAIAI

		else {
			// Check if we can jump forward 2 times 
			if (!HasPawnMoved(cx, cy)) {
				if (!IsThereAPiece(cx, cy - 2) && !IsThereAPiece(cx,cy-1)) {
					if (!WillKingBeInDanger(createmove(cx, cy, cx, cy - 2))) {
						movelist.push_back(createmove(cx, cy, cx, cy - 2));
					}
				}
			}

			// check if we can go on forward
			if (!IsThereAPiece(cx, cy - 1)) {
				if (!WillKingBeInDanger(createmove(cx, cy, cx, cy - 1))) {
					movelist.push_back(createmove(cx, cy, cx, cy - 1));
				}
			}

			// Check if we can eat left
			// Check we arent eating out of the board
			if (!IsItOutOfBoard(cx - 1, cy - 1)) {
				if (IsThereAPiece(cx - 1, cy - 1)) {
					if (IdentifyTurn(cx - 1, cy - 1) == "player") {
						if (!WillKingBeInDanger(createmove(cx, cy, cx + 1, cy - 1))) {
							movelist.push_back(createmove(cx, cy, cx + 1, cy - 1));
						}
					}

				}

			}

			// Check if we can  right
			// Check we arent eating out of the board
			if (!IsItOutOfBoard(cx + 1, cy - 1)) {
				if (IsThereAPiece(cx + 1, cy - 1)) {
					if (IdentifyTurn(cx + 1, cy - 1) == "player") {
						if (!WillKingBeInDanger(createmove(cx, cy, cx + 1, cy - 1))) {
							movelist.push_back(createmove(cx, cy, cx + 1, cy - 1));
						}
					}

				}

			}





		}


		// AI pawn search

	}
}


bool Movegenerator::HaveTurnRanOutOfMoves() {

	GenerateMoves();
	if (getLength() == 0) { return true; }
	else { return false; }
}




