#include <iostream>
#include "board.h"
#include "TermColor.hpp"
bool checkInput(std::string inputStr);
int main() {
	Board newBoard;
	newBoard.printBoard();

	int count = 0;
	while (count < 5) {
		std::string curr = "";
		std::string next = "";
		do
		{
			std::cout << "Move which pawn? ";
			std::cin >> curr;

		} while (checkInput(curr) == false);


		do 
		{
			std::cout << "To where? ";
			std::cin >> next;
		} while (checkInput(next) == false);
		count++;
		newBoard.move(curr, next);
		newBoard.printBoard();
	}
	// freeboard();
	return 1;

};

bool checkInput(std::string  inputStr) {

	try
	{
		char letter = inputStr[0];
		int num = std::stoi(inputStr.substr(1));
		return true;

	}
	catch (const std::exception&)
	{
		std::cout <<termcolor::red<< "Invaild input" << termcolor::white<<std::endl;

	}


}
