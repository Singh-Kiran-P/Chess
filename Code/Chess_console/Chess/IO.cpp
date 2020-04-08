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
	cout << termcolor::green << "   _______________" << endl;
	for (int i = 0; i < 8; i++) {
		cout << termcolor::green << 8 - i << " |" << termcolor::white; //Board is zero-indexed, while the chess game is flipped and has 1 at the bottom
		for (int j = 0; j < 8; j++) {
			Position tempPos{i, j};
			Piece* tempPiece;
			if ((tempPiece = board->getPiece(tempPos)) != nullptr) {

				if (tempPiece->getColor() == Color::Black)
					cout << termcolor::blue;
				cout << tempPiece->getId();
				cout << termcolor::white;

				if (j < 8 - 1)
					cout << " ";
			}
			else {
				cout << ".";
				if (j < 8 - 1)
					cout << " ";
			}
		}
		cout << termcolor::green << '|';
		cout << '\n';
	}
	cout << termcolor::green << "   _______________" << endl;
	cout << "   A B C D E F G H" << termcolor::white << endl;

};

bool checkInput(string inputStr) {
	try {
		char letter = inputStr[0];
		int num = stoi(inputStr.substr(1)) - 1; //input value must be of the form CHARINT
		if (('A' <=  letter <= 'H') && (1 <= num <= 8)) //input value must be between A1 and H8
			return true;
	}
	catch (const exception&) {
		cout << termcolor::red << "Invaild input" << termcolor::white<<endl;
	}
	return false;
};

void printWinner(Player* player) {
    cout << "##################################  ";
    cout <<    player->name() << " won the game!";
    cout << "  ##################################\n" << endl;
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system ("clear");
#endif
};

bool InvalidMove(Player* player) {
	if (auto* playertype = dynamic_cast<HumanPlayer*>(player)) // Only print this error message when a player causes it
		cout << termcolor::red << "Invalid move" << termcolor::white << endl;
	return false;
};
