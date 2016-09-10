//AddStatement.cpp:
#include "AddStatement.h"
#include "ProgramState.h"
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

AddStatement::AddStatement(string variableName, string value)
	:  m_value( value ), m_variableName( variableName )
{}

void AddStatement::execute(ProgramState * state, ostream &outf)
{
	//adding another condition fixes the adding negative numbers
	if((m_value >= "0" && m_value <= "9") || (m_value <= "0" || m_value >= "-9"))
	{
		state->AddInt(m_variableName, atoi(m_value.c_str()));
	}

	state->AddVar(m_variableName, m_value);

	state->nextLine();
}
