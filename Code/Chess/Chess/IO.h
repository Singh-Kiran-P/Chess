#pragma once
const int MAX_SIZE = 8;
#include "TermColor.hpp"
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

bool checkChoice();
void printLogo();
void printWinner(std::string name);
void clearScreen();
