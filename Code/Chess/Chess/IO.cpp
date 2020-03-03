#include "io.h"

bool checkChoice() {
	string choice;

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

bool checkInput(string  inputStr) {
	try {
		char letter = inputStr[0];
		int num = stoi(inputStr.substr(1)) - 1; //input value must be of the form CHARINT
		if (('A' <=  letter <= 'H') && (1 <= num <= MAX_SIZE)) //input value must be between A1 and H8
			return true;
	}
	catch (const exception&) {
		cout << termcolor::red << "Invaild input" << termcolor::white<<endl;
	}
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

}
