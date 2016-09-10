#ifndef DEBUGGER_WINDOW_H
#define DEBUGGER_WINDOW_H
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QApplication>
#include <QString>
#include <QComboBox>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include "Facile.h"
#include "Statement.h"
#include "ProgramState.h"
#include "msort.h"

using namespace std;

class DebuggerWindow : public QWidget
{
	Q_OBJECT

	public:
		DebuggerWindow(ifstream& file);
		~DebuggerWindow();

	private slots:
		void BreakPushed();
		void ContPushed();
		void StepPushed();
		void NextPushed();
		void InspectPushed();
		void QuitPushed();
		void UpdatePushed();
		void HidePushed();
		void DoSorting(int row);

	private:
		//Buttons for Debugger Window 
		QPushButton* BreakPointButton;
		QPushButton* ContinueButton;
		QPushButton* StepButton;
		QPushButton* NextButton;
		QPushButton* InspectButton;
		QPushButton* QuitButton;

		//Create Scroll Box
		QListWidget* ScrollBox;

		//Layout for Debugger Window
		QHBoxLayout* Debugh;
		QVBoxLayout* Debugv;
		QWidget* Window;
		vector<bool> breakpoints;


		//Creating the values window: did not use a separate
		//class for it, but instead used a QWidget to create
		//it and used show() and hide().
		QWidget* valsWindow;
		QPushButton* HideButton;
		QPushButton* UpdateButton;
		QListWidget* pvalues;
		//Dropdown Box
		QComboBox* Combo;
		QHBoxLayout* Valuesh;
		QVBoxLayout* Valuesv;

		//allows to insert into vectors so that we can use mergesort
		//created a separate vector of strings/ints
		map<string, int> mapVals;
		void insertinMap(map<string, int>& vmap);
		vector<string> words;
		vector<int> numbervals;
		vector<string> values;

		//going to use in order to access the functions in
		//ProgramState.cpp and Facile.cpp
		vector<Statement*> program;
		Facile facile;
		ProgramState* interpretation;
};
#endif