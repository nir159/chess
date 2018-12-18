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

	//strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	strcpy_s(msgToGraphics, "krrrrrrrrrrrrrrr################################KRRRRRRRRRRRRRRR1"); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	Board game(msgToGraphics);
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		game.setInstruction(msgFromGraphics);
		/*if (!game.pieceExists()) {
			strcpy_s(msgToGraphics, "1"); chess
		}*/
		if (!game.pieceExists()) {
			strcpy_s(msgToGraphics, "2");
		}
		else if (!game.isPiece()) {
			strcpy_s(msgToGraphics, "3");
		}
		/*if (!game.pieceExists()) {
		strcpy_s(msgToGraphics, "4"); selfChess
		}*/
		else if (!game.isValidRange()) {
			strcpy_s(msgToGraphics, "5");
		}
		else if (game.isSame()) {
			strcpy_s(msgToGraphics, "7");
		}
		else if (!game.isReachable()) {
			strcpy_s(msgToGraphics, "6");
		}
		else {
			strcpy_s(msgToGraphics, "0"); // msgToGraphics should contain the result of the operation
			game.setPlayer(SideFunctions::changePlayer(game.getPlayer()));
		}



		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

	}

	p.close();
}