//GosubStatement.h

#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "GoSubStatement.h"
#include "ProgramState.h"
#include "Statement.h"
using namespace std;

class GoSubStatement: public Statement
{
private:
	int linenum;

public:
	GoSubStatement(int gosubline);
	~GoSubStatement() {}
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif