#include <iostream>
#include "Game.h"
// #include "player.h"
#include "TermColor.hpp"

bool checkInput(std::string inputStr);
bool checkChoice();
void printLogo();
int main() {
	printLogo();
	bool gametype = checkChoice();
	bool checkwin;

	Game newGame{gametype}; // Creates both player objects, randomly assigns them their color

	Board newBoard{}; // Creates the board and places the pawns
	newBoard.printBoard();

	std::string curr;
	std::string next;

	do {
		std::cout << "It's " << (newGame.currentPlayer())->name() << "'s turn" << std::endl;
		if ((newGame.currentPlayer())->is_ai())
			newBoard.AiMove(newGame.currentPlayer());
		else {
			do {
				curr = "";
				next = "";
				do {
					std::cout << "Move which pawn? ";
					std::cin >> curr;
				} while (checkInput(curr) == false);

				do {
					std::cout << "To where? ";
					std::cin >> next;
				} while (checkInput(next) == false);

		} while (newBoard.moveStr(curr, next, newGame.currentPlayer()) == false); // If a move is invalid, a turn isn't skipped

		}

		newBoard.printBoard();
		if ((checkwin = newBoard.checkWin()) == false)
		newGame.nextturn();

	} while (checkwin == false); //as long as no one has won, ask the next player for their move

	std::cout << "\n##################################   ";
	std::cout << (newGame.currentPlayer())->name() << " won the game!";
	std::cout << "   ##################################\n" << std::endl;

	return 1;
};

bool checkInput(std::string  inputStr) {
	try {
		char letter = inputStr[0];
		int num = std::stoi(inputStr.substr(1)) - 1; //input value must be of the form CHARINT
		if (('A' <= letter <= 'H') && (1 <= num <= 8)) //input value must be between A1 and H8
			return true;
	}
	catch (const std::exception&) {
		std::cout << termcolor::red << "Invaild input" << termcolor::white<<std::endl;
	}
	return false;
};

bool checkChoice() {
	std::string choice;

	std::cout << "Choose you gametype" << std::endl;
	std::cout << "1) Player VS Player" << std::endl;
	std::cout << "2) Player VS AI" << std::endl;

	do {
		std::cout << "\nChoice: ";
		std::cin >> choice;

		if (choice == "1")
			return false;
		else if (choice == "2")
			return true;
		else
			std::cout << termcolor::red << "Invaild input" << termcolor::white<<std::endl;
	} while (choice != "1" && choice != "2");

	return false;
}
void printLogo()
{

		cout <<termcolor::green<< "    ======================================\n"<<termcolor::white;
		cout << termcolor::blue << "       _____ _    _ ______  _____ _____\n" << termcolor::white;
		cout << termcolor::blue << "      / ____| |  | |  ____|/ ____/ ____|\n" << termcolor::white;
		cout << termcolor::red << "     | |    | |__| | |__  | (___| (___ \n" << termcolor::white;
		cout << termcolor::red << "     | |    |  __  |  __|  \\___ \\\\___ \\ \n" << termcolor::white;
		cout << termcolor::red << "     | |____| |  | | |____ ____) |___) |\n" << termcolor::white;
		cout << termcolor::blue << "      \\_____|_|  |_|______|_____/_____/\n\n" << termcolor::white;
		cout << termcolor::green << "    ======================================\n\n"<<termcolor::white;

};
