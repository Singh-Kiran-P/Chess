#pragma once
const int MAX_SIZE = 8;
#include "TermColor.hpp"
#include "humanplayer.h"
#include "board.h"
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

bool checkChoice();
void printLogo();
void printBoard(Board* board);
void printWinner(Player* player);
bool checkInput(string inputStr);
void clearScreen();
bool InvalidMove(Player* player);
