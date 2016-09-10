#ifndef FACILE_H
#define FACILE_H
#include <vector>
#include <string>
#include <sstream>
#include "Statement.h"

using namespace std;

class Facile
{
	public:
		void parseProgram(istream& inf, vector<Statement*> & program);
		Statement* parseLine(string line);
		void interpretProgram(istream& inf, ostream& outf);

	private:
};
#endif