//Add.h

#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "AddStatement.h"
#include "ProgramState.h"
#include "Statement.h"
using namespace std;

class AddStatement: public Statement
{
private:
	string m_value;
	string m_variableName;

public:
	AddStatement(string variablename, string value);
	virtual ~AddStatement() {}
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif