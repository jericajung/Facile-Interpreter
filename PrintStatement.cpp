// PrintStatement.cpp
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}

void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	outf << state->GetVar(m_variableName) << std::endl;
	state->nextLine();
}