//SubStatement.cpp:
#include "SubStatement.h"
#include "ProgramState.h"
#include <string>
#include <stdlib.h>
using namespace std;

SubStatement::SubStatement(string variableName, string value)
	:m_value( value ), m_variableName( variableName )
{}

void SubStatement::execute(ProgramState * state, ostream &outf)
{
	if((m_value >= "0" && m_value <= "9") || (m_value <= "0" || m_value >= "-9"))
	{
		state->SubInt(m_variableName, atoi(m_value.c_str()));
	}

	state->SubVar(m_variableName, m_value);

	state->nextLine();
}
