//IfStatement.h

#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "IfStatement.h"
#include "ProgramState.h"
#include "Statement.h"
using namespace std;

class IfStatement: public Statement
{
private:
	string m_variable;
	string m_operator;
	int value;
	int linenumber;

public:
	IfStatement(string variablename, string operate, int val, int linenum);
	virtual ~IfStatement() {}
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif