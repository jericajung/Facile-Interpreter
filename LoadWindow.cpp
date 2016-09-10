#include "LoadWindow.h"
#include <fstream>

using namespace std;

LoadWindow::LoadWindow()
{
	setWindowTitle("Facile Debugger");


	//Overall Layout
	OverallLayout = new QVBoxLayout();

	//Add Filename
	//Layout
	FormLayout = new QVBoxLayout();
	OverallLayout->addLayout(FormLayout);

	//Filename
	FileLabel = new QLabel("Enter Filename:");
	FormLayout->addWidget(FileLabel);

	FileInput = new QLineEdit();
	FormLayout->addWidget(FileInput);

	//Enter Button
	EnterButton = new QPushButton("Load");
	connect(EnterButton, SIGNAL(clicked()), this, SLOT(EnterFile()));
	FormLayout->addWidget(EnterButton);

	//Quit Button
	QuitButton = new QPushButton("Quit");
	connect(QuitButton, SIGNAL(clicked()), this, SLOT(Quit()));
	FormLayout->addWidget(QuitButton);

	FormLayout->addWidget(FileInput);
	connect(FileInput, SIGNAL(returnPressed()), this, SLOT(EnterFile()));
	
	//Set overall Layout
	setLayout(OverallLayout);
	show();
}

LoadWindow::~LoadWindow()
{
	//did not delete anything because when i do
	//and press quit on the debugger window, it
	//gives a seg fault
}

void LoadWindow::EnterFile()
{
	ifstream filename(FileInput->text().toStdString());
	if(filename.fail() || FileInput->text().isEmpty())
	{
		QMessageBox message;
		message.setText("The file entered does not work!");
		message.setInformativeText("Please try again.");
		message.setStandardButtons(QMessageBox::Cancel);
		message.exec();
	}

	else
	{
		DebugWin = new DebuggerWindow(filename);
		setVisible(false);
	}
}

void LoadWindow::Quit()
{
	QApplication::exit();
}