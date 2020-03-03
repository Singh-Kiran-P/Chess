#ifndef IO
#define IO
#define MAX_SIZE 8
#include "TermColor.hpp"
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iostream>
using namespace std;

bool checkInput(std::string inputStr);
bool checkChoice();
void printLogo();
void printWinner(std::string name);

#endif
