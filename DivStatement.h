//DivStatement.h

#ifndef Div_STATEMENT_INCLUDED
#define Div_STATEMENT_INCLUDED

#include "DivStatement.h"
#include "ProgramState.h"
#include "Statement.h"
using namespace std;

class DivStatement: public Statement
{
private:
	string m_value;
	string m_variableName;

public:
	DivStatement(string variablename, string value);
	virtual ~DivStatement() {}
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif