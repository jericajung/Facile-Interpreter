//Mult.cpp:
#include "MultStatement.h"
#include "ProgramState.h"
#include <string>
#include <stdlib.h>
using namespace std;

MultStatement::MultStatement(string variableName, string value)
	: m_value( value ), m_variableName( variableName )
{}

void MultStatement::execute(ProgramState * state, ostream &outf)
{
	if((m_value >= "0" && m_value <= "9") || (m_value <= "0" && m_value >= "-9"))
	{
		state->MultInt(m_variableName, atoi(m_value.c_str()));
	}

	state->MultVar(m_variableName, m_value);

	state->nextLine();
}
