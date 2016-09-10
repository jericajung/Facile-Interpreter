// ProgramState.h
//
// CS 104 / Spring 2016
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include "stackint.h"
#include <map>
#include <string>

class ProgramState
{
public:
	ProgramState(int maxlines);
	int returncounter();
	void LetSetIt(std::string variable, int value);
	void GotoLine(int line);
	void nextLine();
	void PrintAll();
	void EndProgram();
	void PushStack();
	void PopStack();
	int GetVar(std::string variable);

	//Created separate functions for each of the operators
	//and to determine if adding a variable or integer
	void AddInt(std::string variable, int value);
	void AddVar(std::string variable, std::string othervariable);
	void SubInt(std::string variable, int value);
	void SubVar(std::string variable, std::string othervariable);
	void MultInt(std::string variable, int value);
	void MultVar(std::string variable, std::string othervariable);
	void DivInt(std::string variable, int value);
	void DivVar(std::string variable, std::string othervariable);

	//functions to use in Debugger Window, so that we can implement
	//some of the functions
	int getCounter();
	void setCounter(int count);
	std::map<std::string, int> getMymap(); //returns the map contents
	std::map<std::string, int> clearMymap();

private:
	int currline;
	std::string mapvariable;
	int mapvalue;
	int counter;
	int max_lines;
	std::map<std::string, int> Mymap;
	StackInt stacked;
};

#endif



