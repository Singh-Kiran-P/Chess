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
