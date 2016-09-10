// GotoStatement.cpp:
#include "GotoStatement.h"
using namespace std;

GotoStatement::GotoStatement(int linenum)
	: m_line(linenum)
{}

void GotoStatement::execute(ProgramState * state, ostream &outf)
{
	state->GotoLine(m_line);
}