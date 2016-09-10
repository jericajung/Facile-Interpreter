//Div.cpp:
#include "DivStatement.h"
#include "ProgramState.h"
#include <string>
#include <stdlib.h>
using namespace std;

DivStatement::DivStatement(string variableName, string value)
	:m_value( value ), m_variableName( variableName )
{}

void DivStatement::execute(ProgramState * state, ostream &outf)
{
	if((m_value >= "0" && m_value <= "9") || (m_value <= "0" && m_value >= "-9"))
	{
		state->DivInt(m_variableName, atoi(m_value.c_str()));
	}

	state->DivVar(m_variableName, m_value);

	state->nextLine();
}
