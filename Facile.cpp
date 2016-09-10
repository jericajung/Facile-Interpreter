// Facile.cpp
#include "Statement.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "PrintAll.h"
#include "ProgramState.h"
#include "EndStatement.h"
#include "GotoStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "GoSubStatement.h"
#include "ReturnStatement.h"
#include "IfStatement.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include "Facile.h"


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);

/*int main()
{
		cout << "Enter Facile program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
        		cout << "Cannot open " << filename << "!" << endl;
        		return 1;
        }
        interpretProgram(infile, cout);
        infile.close();
        return 0;
}*/

void Facile::parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}

Statement * Facile::parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	string var2;
	int val;
	int val2;

	ss << line;
	ss >> type;

	if(type == "LET")
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal Facile program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	else if(type == "PRINT")
	{
		ss >> var;
		statement = new PrintStatement(var);
	}

	else if(type == "PRINTALL")
	{
		statement = new PrintAll();
	}

	else if(type == "ADD")
	{
		ss >> var;
		ss >> var2;
		statement = new AddStatement(var, var2);
	}

	else if(type == "SUB")
	{
		ss >> var;
		ss >> var2;
		statement = new SubStatement(var, var2);
	}

	else if(type == "MULT")
	{
		ss >> var;
		ss >> var2;
		statement = new MultStatement(var, var2);
	}

	else if(type == "DIV")
	{
		ss >> var;
		ss >> var2;
		statement = new DivStatement(var, var2);
	}

	else if(type == "GOTO")
	{
		ss >> val;
		statement = new GotoStatement(val);		
	}

	else if(type == "IF")
	{
		ss >> var;
		ss >> var2; //gives the operator
		ss >> val;
		ss >> type; //would be THEN
		ss >> val2;

		statement = new IfStatement(var, var2, val, val2);
	}

	else if(type == "GOSUB")
	{
		ss >> val;
		statement = new GoSubStatement(val);
		//gosubs.insert(val);
	}

	else if(type == "RETURN")
	{
		statement = new ReturnStatement();
		//returns.insert();
	}

	else if(type == "." || type == "END")
	{
		statement = new EndStatement();
	}

	return statement;
}


void Facile::interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram(inf, program);
	ProgramState* interpretation = new ProgramState(program.size()-1);

	//Would run until the program counter reaches zero
	int programcount = 1;
	while(programcount != 0)
	{
		program[programcount]->execute(interpretation, outf);
		programcount = interpretation->returncounter();
	}

	for(unsigned int i=1; i<program.size(); i++)
	{
		delete program[i];
	}

	delete interpretation;
}

