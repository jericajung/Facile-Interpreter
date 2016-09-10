//SubStatement.h

#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "SubStatement.h"
#include "ProgramState.h"
#include "Statement.h"
using namespace std;

class SubStatement: public Statement
{
private:
	string m_value;
	string m_variableName;

public:
	SubStatement(string variablename, string value);
	virtual ~SubStatement() {}
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif