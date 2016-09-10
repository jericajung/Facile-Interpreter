//GoSubStatement.cpp:
#include "GoSubStatement.h"
#include "ProgramState.h"
#include <string>
#include <stdlib.h>
using namespace std;

GoSubStatement::GoSubStatement(int gosubline)
	: linenum(gosubline)
{}

void GoSubStatement::execute(ProgramState * state, ostream &outf)
{
	state->PushStack();
	state->GotoLine(linenum);
}
