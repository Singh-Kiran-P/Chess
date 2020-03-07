#include "humanplayer.h"

Position HumanPlayer::moveFrom(Color playerColor) {
        std::string curr{};

        do {
            curr = "";
            std::cout << "Move which pawn? ";
            std::cin >> curr;
            curr[0] = toupper(curr[0]);
        } while (checkInput(curr) == false);

        Position currPos{curr};
        return currPos;
};

Position HumanPlayer::moveTo(Position currPos, Color playerColor) {
    std::string next{};

    do {
        next = "";
        std::cout << "To where? ";
        std::cin >> next;
        next[0] = toupper(next[0]);
    } while (checkInput(next) == false);

    Position nextPos{next};
    return nextPos;
}


bool HumanPlayer::checkInput(string  inputStr) {
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

HumanPlayer::HumanPlayer(string nameStr, Color color) : Player(nameStr, color) {};
