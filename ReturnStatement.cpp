//ReturnStatement.cpp:
#include "ReturnStatement.h"
#include "ProgramState.h"
#include <string>
#include <stdlib.h>
using namespace std;

ReturnStatement::ReturnStatement()
{}

void ReturnStatement::execute(ProgramState * state, ostream &outf)
{
	state->PopStack();
}
