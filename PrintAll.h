
#ifndef PRINT_ALL_INCLUDED
#define PRINT_ALL_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include <iostream>

class PrintAll: public Statement
{
private:
	std::string m_variablename;
	int m_value;
	
public:
	PrintAll();
	virtual ~PrintAll() {}
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
