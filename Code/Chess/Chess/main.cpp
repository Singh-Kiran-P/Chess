﻿#include <iostream>
#include "game.h"

int main() {
	printLogo();
    bool gametype = checkChoice(); //VS AI || VS Player
    Game newGame{ gametype }; // Creates both player objects, randomly assigns them their color	newGame.run();
    newGame.run(newGame);
	return 1;
};
