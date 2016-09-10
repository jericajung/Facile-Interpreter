//Mult.h

#ifndef Mult_STATEMENT_INCLUDED
#define Mult_STATEMENT_INCLUDED

#include "MultStatement.h"
#include "ProgramState.h"
#include "Statement.h"
using namespace std;

class MultStatement: public Statement
{
private:
	string m_value;
	string m_variableName;

public:
	MultStatement(string variablename, string value);
	virtual ~MultStatement() {}
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif