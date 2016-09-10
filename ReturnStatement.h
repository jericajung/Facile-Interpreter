//ReturnStatement.h

#ifndef RETURN_STATEMENT_INCLUDED
#define RETURN_STATEMENT_INCLUDED

#include "ReturnStatement.h"
#include "ProgramState.h"
#include "Statement.h"
using namespace std;

class ReturnStatement: public Statement
{
private:
	

public:
	ReturnStatement();
	virtual ~ReturnStatement() {}
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif