// GotoStatement.h

#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class GotoStatement : public Statement
{
private:
	int m_line;

public:
	GotoStatement(int linenum);
	~GotoStatement() {}

	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
