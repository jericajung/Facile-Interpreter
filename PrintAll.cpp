// PrintAll.cpp:
#include "PrintAll.h"
#include "ProgramState.h"
#include <map>
#include <iostream>

PrintAll::PrintAll()
{}

void PrintAll::execute(ProgramState * state, std::ostream &outf)
{
	state->PrintAll();
	state->nextLine();
}

