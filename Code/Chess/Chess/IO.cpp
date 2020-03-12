#include "io.h"

bool checkChoice() {
	string choice{};

	cout << "Choose you gametype" << endl;
	cout << "1) Player VS Player" << endl;
	cout << "2) Player VS AI" << endl;

	do {
		cout << "\nChoice: ";
		cin >> choice;

		if (choice == "1")
			return false;
		else if (choice == "2")
			return true;
		else
			cout << termcolor::red << "Invaild input" << termcolor::white<<endl;
	} while (choice != "1" && choice != "2");

	return false;
};

void printLogo()
{

		cout << termcolor::green<< "    ======================================\n"<<termcolor::white;
		cout << termcolor::blue << "       _____ _    _ ______  _____ _____\n" << termcolor::white;
		cout << termcolor::blue << "      / ____| |  | |  ____|/ ____/ ____|\n" << termcolor::white;
		cout << termcolor::red << "     | |    | |__| | |__  | (___| (___ \n" << termcolor::white;
		cout << termcolor::red << "     | |    |  __  |  __|  \\___ \\\\___ \\ \n" << termcolor::white;
		cout << termcolor::red << "     | |____| |  | | |____ ____) |___) |\n" << termcolor::white;
		cout << termcolor::blue << "      \\_____|_|  |_|______|_____/_____/\n\n" << termcolor::white;
		cout << termcolor::green << "    ======================================\n\n"<<termcolor::white;

};

void printBoard(Board* board) {
	std::cout << termcolor::green << "   _______________" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << termcolor::green << 8 - i << " |" << termcolor::white; //Board is zero-indexed, while the chess game is flipped and has 1 at the bottom
		for (int j = 0; j < 8; j++) {
			Position tempPos{i, j};
			Piece* tempPiece;
			if ((tempPiece = board->getPiece(tempPos)) != nullptr) {

				if (tempPiece->getColor() == Color::Black)
					std::cout << termcolor::blue;
				std::cout << tempPiece->getId();
				std::cout << termcolor::white;

				if (j < 8 - 1)
					std::cout << " ";
			}
			else {
				std::cout << ".";
				if (j < 8 - 1)
					std::cout << " ";
			}
		}
		std::cout << termcolor::green << '|';
		std::cout << '\n';
	}
	std::cout << termcolor::green << "   _______________" << std::endl;
	std::cout << "   A B C D E F G H" << termcolor::white << std::endl;

};

void printWinner(string name) {
    cout << "\n##################################   ";
    cout <<    name << " won the game!";
    cout << "   ##################################\n" << endl;
    cin;

};

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system ("clear");
#endif
};

bool InvalidMove(Player* player) {
	if (auto* playertype = dynamic_cast<HumanPlayer*>(player)) // Only print this error message when a player causes it
		std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
	return false;
};
