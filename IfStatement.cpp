//AddStatement.cpp:
#include "IfStatement.h"
#include "ProgramState.h"
#include <string>
#include <stdlib.h>
using namespace std;

IfStatement::IfStatement(string variablename, string operate, int val, int linenum)
	: m_variable( variablename ), m_operator( operate ), value( val ), linenumber( linenum )
{}

void IfStatement::execute(ProgramState * state, ostream &outf)
{

	int getvalue = state->GetVar(m_variable);
	if(m_operator == "<")
	{
		//if statement is true go to line
		if(getvalue < value)
		{
			state->GotoLine(linenumber);
		}

		//if not move onto next line
		else
		{
			state->nextLine();
		}
	}

	else if(m_operator == "<=")
	{
		if(getvalue <= value)
		{
			state->GotoLine(linenumber);
		}

		else
		{
			state->nextLine();
		}
	}

	else if(m_operator == "=")
	{
		if(getvalue == value)
		{
			state->GotoLine(linenumber);
		}

		else
		{
			state->nextLine();
		}
	}

	else if(m_operator == ">")
	{
		if(getvalue > value)
		{
			state->GotoLine(linenumber);
		}

		else
		{
			state->nextLine();
		}
	}

	else if(m_operator == ">=")
	{
		if(getvalue >= value)
		{
			state->GotoLine(linenumber);
		}

		else
		{
			state->nextLine();
		}	
	}

	else if(m_operator == "<>")
	{
		if(getvalue != value)
		{
			state->GotoLine(linenumber);
		}
		
		else
		{
			state->nextLine();
		}
	}
}
