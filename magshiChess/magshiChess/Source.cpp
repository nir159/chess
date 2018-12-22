#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Board.h"

using namespace std;
void main()
{
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	p.sendMessageToGraphics(msgToGraphics); // send the board string
	Board game(msgToGraphics);
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		game.setInstruction(msgFromGraphics);
		game.setIsPlayerDst();
		if (!game.pieceExists()) { // if piece does not exist
			strcpy_s(msgToGraphics, "2");
		}
		else if (!game.isPiece()) { // if piece of the current player exist
			strcpy_s(msgToGraphics, "3");
		}
		else if (game.isSelfChess()) { // if move will cause chess to current player
			strcpy_s(msgToGraphics, "4");
		}
		else if (!game.isValidRange()) { // if move is not in the range
			strcpy_s(msgToGraphics, "5");
		}
		else if (game.isSame()) { // if destination is the same as source
			strcpy_s(msgToGraphics, "7");
		}
		else if (!game.isReachable()) { // if the destination is not reachable
			strcpy_s(msgToGraphics, "6");
		}
		else {
			strcpy_s(msgToGraphics, "0");
			if (game.isChess()) { // if the move caused chess to the other player
				strcpy_s(msgToGraphics, "1");
			}
			game.setPlayer(SideFunctions::changePlayer(game.getPlayer())); // after the move was made changes the current player
		}



		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

	}

	p.close();
}