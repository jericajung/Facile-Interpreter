#include "ProgramState.h"
#include "stackint.h"
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

ProgramState::ProgramState(int maxlines) :max_lines(maxlines)
{
	counter = 1;
}

//program counter
void ProgramState::nextLine()
{
	counter++;
}

//allows us to know what the counter is and when to
//stop the program
int ProgramState::returncounter()
{
	return counter;
}

//function would insert into map with a variable name
//and a value (would be used for LET statement)
void ProgramState::LetSetIt(string variable, int value)
{
	map<string, int>::iterator it = Mymap.find(variable);
	if(it != Mymap.end())
	{
		it->second = value;
	}

	else
	{
		Mymap.insert(make_pair(variable, value));
	}
}

void ProgramState::GotoLine(int line)
{
	//if the GOTO line is a blank
	if(line < 1 || line > max_lines)
	{
		//cout << "Illegal jump instruction." << endl;
		throw out_of_range("Illegal jump instruction.");
		counter = 0;
	}

	else
	{
		counter = line;
	}
}

//prints all the keys and values in the map
void ProgramState::PrintAll()
{
	map<string, int>::iterator it;
	for(it = Mymap.begin(); it != Mymap.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}

//used by the END or . statement
void ProgramState::EndProgram()
{
	counter = 0;
}

//GOSUB STATEMENT
void ProgramState::PushStack()
{
	stacked.push(counter);
}

//RETURN STATEMENT
void ProgramState::PopStack()
{
	if(stacked.empty())
	{
		cout << "NOTHING IN THE STACK." << endl;
		counter = 0;
	}
	
	else
	{
		counter = stacked.top()+1;
		stacked.pop();
	}
}
/*
void ProgramState::getStack()
{
	return stacked;
}*/

//getting the value of the variable
int ProgramState::GetVar(string variable)
{
	if(Mymap.find(variable) != Mymap.end())
	{
		return Mymap[variable];
	}

	else
	{
		Mymap.insert(make_pair(variable, 0));
		return 0;
	}
}

//If Adding an integer: very similar to subtract,
//multiply, and divide except for the differences
//in operators
void ProgramState::AddInt(string variable, int value)
{
	//Add the value to the current variable's value
	if(Mymap.find(variable) != Mymap.end())
	{
		int newint = Mymap[variable] + value;
		Mymap[variable] = newint;
	}

	//If not in map, insert it.
	else
	{
		Mymap.insert(make_pair(variable, value));
	}
}

//If Adding a variable: very similar to subtract,
//multiply, and divide except for the differences
//in operators
void ProgramState::AddVar(string variable, string othervariable)
{
	//Find the first variable
	if(Mymap.find(variable) != Mymap.end())
	{
		int newint = Mymap[variable];
		int anothernewint = 0;
		//Finding the second variable
		if(Mymap.find(othervariable) != Mymap.end())
		{
			anothernewint = Mymap[othervariable];
		}
		//If both are found, add them together
		Mymap[variable] = newint + anothernewint;
	}

	else
	{
		int anothernewint = 0;
		//If the second variable is found, but not the first
		if(Mymap.find(othervariable) != Mymap.end())
		{
			anothernewint = Mymap[othervariable];
		}

		//Add the first variable to the map
		Mymap.insert(make_pair(variable, anothernewint));
	}
}

void ProgramState::SubInt(string variable, int value)
{
	if(Mymap.find(variable) != Mymap.end())
	{
		int newint = Mymap[variable] - value;
		Mymap[variable] = newint;
	}

	else
	{
		Mymap.insert(make_pair(variable, value));
	}
}

void ProgramState::SubVar(string variable, string othervariable)
{
	if(Mymap.find(variable) != Mymap.end())
	{
		int newint = Mymap[variable];
		int anothernewint = 0;
		if(Mymap.find(othervariable) != Mymap.end())
		{
			anothernewint = Mymap[othervariable];
		}

		Mymap[variable] = newint - anothernewint;
	}

	else
	{
		int anothernewint = 0;
		if(Mymap.find(othervariable) != Mymap.end())
		{
			anothernewint = Mymap[othervariable];
		}
		Mymap.insert(make_pair(variable, anothernewint));
	}
}

void ProgramState::MultInt(string variable, int value)
{
	if(Mymap.find(variable) != Mymap.end())
	{
		int newint = Mymap[variable] * value;
		Mymap[variable] = newint;
	}

	else
	{
		Mymap.insert(make_pair(variable, value));
	}
}

void ProgramState::MultVar(string variable, string othervariable)
{
	if(Mymap.find(variable) != Mymap.end())
	{
		int newint = Mymap[variable];
		int anothernewint = 0;
		if(Mymap.find(othervariable) != Mymap.end())
		{
			anothernewint = Mymap[othervariable];
			Mymap[variable] = newint * anothernewint;
		}
	}

	else
	{
		int anothernewint = 0;
		if(Mymap.find(othervariable) != Mymap.end())
		{
			anothernewint = Mymap[othervariable];
		}
		Mymap.insert(make_pair(variable, anothernewint));
	}
}

void ProgramState::DivInt(string variable, int value)
{
	if(Mymap.find(variable) != Mymap.end())
	{
		if(value == 0)
		{
			throw logic_error("Divide by zero not allowed.");
			return;
		}

		else
		{
			int newint = Mymap[variable] / value;
			Mymap[variable] = newint;
		}
	}

	else
	{
		Mymap.insert(make_pair(variable, value));
	}
}

void ProgramState::DivVar(string variable, string othervariable)
{
	if(Mymap.find(variable) != Mymap.end())
	{
		int newint = Mymap[variable];
		if(Mymap.find(othervariable) != Mymap.end())
		{
			if(Mymap[othervariable] == 0)
			{
				throw logic_error("Divide by zero not allowed.");
			}

			else
			{
				Mymap[variable] = newint / Mymap[othervariable];
			}
		}
	}

	else
	{
		int anothernewint = 0;
		if(Mymap.find(othervariable) != Mymap.end())
		{
			anothernewint = Mymap[othervariable];
		}
		Mymap.insert(make_pair(variable, anothernewint));
	}
}

//gets the counter
int ProgramState::getCounter()
{
	return counter;
}

//would be set to 0 or 1 depending on if you want to
//continue on with the program or not
void ProgramState::setCounter(int count)
{
	counter = count;
}

//returns the contents of the map
map<string, int> ProgramState::getMymap()
{
	return Mymap;
}

//clears the map
map<string, int> ProgramState::clearMymap()
{
	Mymap.clear();
	return Mymap;
}
