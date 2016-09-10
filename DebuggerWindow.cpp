//Debugger Window
#include "DebuggerWindow.h"
#include "Facile.h"
#include "Statement.h"
#include "ProgramState.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

DebuggerWindow::DebuggerWindow(ifstream& file)
{
	//Create a scroll box to put the contents in
	ScrollBox = new QListWidget();

	//Display contents of the file
	program.push_back(NULL);
	string something;
	while(!file.eof())
	{
		getline(file, something);
		QString line = QString::fromStdString(something);
		ScrollBox->addItem(line);
		ScrollBox->item(0)->setBackground(Qt::yellow);
		program.push_back(facile.parseLine(something));
	}
	interpretation = new ProgramState(program.size()-1);

	//initialize the breakpoints as false
	for(unsigned int i =0; i<program.size()-1; i++)
	{
		breakpoints.push_back(false);
	}


	Debugh = new QHBoxLayout();
	Debugv = new QVBoxLayout();
	Window = new QWidget();

	//Breakpoint Button
	BreakPointButton = new QPushButton("Add/Delete Breakpoint");
	Debugh->addWidget(BreakPointButton);
	connect(BreakPointButton, SIGNAL(clicked()), this, SLOT(BreakPushed()));

	//Continue Button
	ContinueButton = new QPushButton("Continue");
	Debugh->addWidget(ContinueButton);
	connect(ContinueButton, SIGNAL(clicked()), this, SLOT(ContPushed()));

	//Step Button
	StepButton = new QPushButton("Step");
	Debugh->addWidget(StepButton);
	connect(StepButton, SIGNAL(clicked()), this, SLOT(StepPushed()));

	//Next Button
	NextButton = new QPushButton("Next");
	Debugh->addWidget(NextButton);
	connect(NextButton, SIGNAL(clicked()), this, SLOT(NextPushed()));

	//Inspect Button
	InspectButton = new QPushButton("Inspect");
	Debugh->addWidget(InspectButton);
	connect(InspectButton, SIGNAL(clicked()), this, SLOT(InspectPushed()));

	//Quit Button
	QuitButton = new QPushButton("Quit");
	Debugh->addWidget(QuitButton);
	connect(QuitButton, SIGNAL(clicked()), this, SLOT(QuitPushed()));

	//Shows the Debugger Screen
	Debugv->addWidget(ScrollBox);
	Debugv->addLayout(Debugh);
	Window->setLayout(Debugv);
	Window->setWindowTitle("Facile Debugger");
	Window->show();

	//Creating the values window
	Valuesh = new QHBoxLayout();
	Valuesv = new QVBoxLayout();
	valsWindow = new QWidget();
	pvalues = new QListWidget();

	//Hide Button
	HideButton = new QPushButton("Hide");
	connect(HideButton, SIGNAL(clicked()), this, SLOT(HidePushed()));
	Valuesv->addWidget(HideButton);

	//Update Button
	UpdateButton = new QPushButton("Update");
	connect(UpdateButton, SIGNAL(clicked()), this, SLOT(UpdatePushed()));
	Valuesv->addWidget(UpdateButton);

	//Creating a dropbox Layout--merge sort is going to be used
	Combo = new QComboBox();
	Combo->addItem("Order Strings in Ascending order");
	Combo->addItem("Order Strings in Descending order");
	Combo->addItem("Order Ints in Ascending order");
	Combo->addItem("Order Ints in Descending order");
	Valuesv->addWidget(Combo);

	Valuesh->addWidget(pvalues);
	Valuesh->addLayout(Valuesv);

	valsWindow->setLayout(Valuesh);
	valsWindow->setWindowTitle("Values Window.");
}

DebuggerWindow::~DebuggerWindow()
{
	delete HideButton;
	delete UpdateButton;
	delete Combo;
	delete Valuesh;
	delete Valuesv;
	delete valsWindow;
	delete pvalues;

	delete Debugh;
	delete Valuesh;
	delete ScrollBox;
	delete BreakPointButton;
	delete ContinueButton;
	delete StepButton;
	delete NextButton;
	delete InspectButton;
	delete QuitButton;
	delete Window;
	delete interpretation;
}

void DebuggerWindow::BreakPushed()
{
	int SelectedNumLine = ScrollBox->currentRow();
	//if already a breakpoint
	if(breakpoints[SelectedNumLine+1] == true)
	{
		breakpoints[SelectedNumLine+1] = false;
		ScrollBox->item(SelectedNumLine)->setBackground(Qt::white);
	}

	//if not already a breakpoint
	else
	{
		breakpoints[SelectedNumLine+1] = true;
		ScrollBox->item(SelectedNumLine)->setBackground(Qt::red);
	}
}

void DebuggerWindow::ContPushed()
{
	while(interpretation->getCounter() != 0)
	{
		//keeps on executing until reaches until hits a breakpoint
		if(breakpoints[interpretation->getCounter()] == false)
		{
			//used in continue, step, and next: indicates an out of range if
			//a GOTO, IF statement, or GOSUB is out of boundaries and the logic_error
			//is when a divide by zero occurs
			try
			{
				program[interpretation->getCounter()]->execute(interpretation, cout);
			}

			catch(out_of_range)
			{
				QMessageBox::warning(this, "Error Message", "Error Occurred: Illegal jump Instruction", "Cancel");
				break;
			}

			catch(logic_error)
			{
				QMessageBox::warning(this, "Error Message", "Error Occurred: Divide by zero", "Cancel");
				break;
			}
		}

		else
		{
			break;
		}
	}
}

void DebuggerWindow::StepPushed()
{
	//executes one line at a time
	if(interpretation->getCounter() != 0)
	{
		try
		{
			program[interpretation->getCounter()]->execute(interpretation, cout);
		}

		catch(out_of_range)
		{
			QMessageBox::warning(this, "Error Message", "Error Occurred: Illegal jump Instruction", "Cancel");
		}

		catch(logic_error)
		{
			QMessageBox::warning(this, "Error Message", "Error Occurred: Divide by zero", "Cancel");
		}

		//when the counter does reach 0, set the counter 
		//back to one and clear the map so it goes back to
		//the start of the file
		if(interpretation->getCounter() == 0)
		{
			interpretation->setCounter(1);
			interpretation->clearMymap();
		}

		for(int i=0; i<ScrollBox->count(); i++)
		{
			ScrollBox->item(i)->setBackground(Qt::white);
		}
		ScrollBox->item(interpretation->getCounter()-1)->setBackground(Qt::yellow);
	}
}

void DebuggerWindow::NextPushed()
{
	stringstream ss(ScrollBox->item(interpretation->getCounter()-1)->text().toStdString());
	string something;
	ss >> something;

	//when reaches a GOSUB--keeps executing until hits RETURN, reaches a breakpoint, or an end statement
	if(something == "GOSUB")
	{
		//StepPushed();
		ss >> something;
		if(something != "RETURN" && breakpoints[ScrollBox->currentRow()] == false)
		{
			if(interpretation->getCounter() != 0)
			{
				try
				{
					program[interpretation->getCounter()]->execute(interpretation, cout);
				}

				catch(out_of_range)
				{
					QMessageBox::warning(this, "Error Message", "Error Occurred: Illegal jump Instruction", "Cancel");
				}

				catch(logic_error)
				{
					QMessageBox::warning(this, "Error Message", "Error Occurred: Divide by zero", "Cancel");
				}
			}
		}

		else if(something == "RETURN" || breakpoints[ScrollBox->currentRow()] == true)
		{
			interpretation->setCounter(1);
			interpretation->clearMymap();
		}
	}

	//program will stop if it sees a RETURN, END, or breakpoint
	else if(something == "RETURN" || breakpoints[ScrollBox->currentRow()] == true)
	{
		interpretation->setCounter(1);
		interpretation->clearMymap();
	}

	else
	{
		StepPushed();
	}
}

//when Inspect is pushed, then values window would open
void DebuggerWindow::InspectPushed()
{
	UpdatePushed();
	valsWindow->show();
}

void DebuggerWindow::QuitPushed()
{
	QApplication::exit();
}

//hides the values window
void DebuggerWindow::HidePushed()
{
	valsWindow->hide();
}

//updates the keys & values in the map
void DebuggerWindow::UpdatePushed()
{
	//insert the map Values into the vector by getting the map
	mapVals = interpretation->getMymap();
	insertinMap(mapVals);
	DoSorting(Combo->currentIndex());
	pvalues->clear();
	for(unsigned int i=0; i<values.size(); i++)
	{
		pvalues->addItem(QString::fromStdString(values[i]));
	}
}

//Using a templated merge sort in order to order strings or ints
//Ascend and Descend are defined in msort.h
void DebuggerWindow::DoSorting(int row)
{
	//Orders strings in ascending order
	if(row == 0)
	{
		Ascend<string> comp;
		mergeSort(words, comp);
		values.clear();
		for(unsigned int i=0; i<words.size(); i++)
		{
			stringstream ss;
			ss << words[i] << " " << mapVals[words[i]];
			//push into the vector
			values.push_back(ss.str());
		}
	}

	//Orders strings in descending order
	else if(row == 1)
	{
		Descend<string> comp;
		mergeSort(words, comp);
		values.clear();
		for(unsigned int i=0; i<words.size(); i++)
		{
			stringstream ss;
			ss << words[i] << " " << mapVals[words[i]];
			values.push_back(ss.str());
		}
	}

	//Orders ints in ascending order
	else if(row == 2)
	{
		Ascend<int> comp;
		mergeSort(numbervals, comp);
		values.clear();
		map<string, int> mymap = mapVals;
		for(unsigned int i =0; i<numbervals.size(); i++)
		{
			stringstream ss;
			string name;
			map<string, int>::iterator it;
			for(it = mymap.begin(); it != mymap.end(); ++it)
			{
				//if found the value
				if(it->second == numbervals[i])
				{
					name = it->first;
					mymap.erase(it);
					break;
				}
			}
			ss << name << " " << numbervals[i];
			values.push_back(ss.str());
		}
	}

	//Orders ints in descending order
	else if(row == 3)
	{
		Descend<int> comp;
		mergeSort(numbervals, comp);
		values.clear();
		map<string, int> mymap = mapVals;
		for(unsigned int i =0; i<numbervals.size(); i++)
		{
			stringstream ss;
			string name;
			map<string, int>::iterator it;
			for(it = mymap.begin(); it != mymap.end(); ++it)
			{
				if(it->second == numbervals[i])
				{
					name = it->first;
					mymap.erase(it);
					break;
				}
			}
			ss << name << " " << numbervals[i];
			values.push_back(ss.str());
		}
	}
}

//allows to get the variables and vals in the map
void DebuggerWindow::insertinMap(map<string, int>& vmap)
{
	words.clear();
	numbervals.clear();
	for(map<string, int>::iterator it=vmap.begin(); it !=vmap.end(); ++it)
	{
		words.push_back(it->first);
		numbervals.push_back(it->second);
	}
}