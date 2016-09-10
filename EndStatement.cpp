//EndProgram.cpp:
#include "EndStatement.h"
#include "ProgramState.h"
using namespace std;

EndStatement::EndStatement()
{}

void EndStatement::execute(ProgramState * state, ostream &outf)
{
	state->EndProgram();
}
