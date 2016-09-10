#ifndef LOAD_WINDOW_H
#define LOAD_WINDOW_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QApplication>
#include "DebuggerWindow.h"
#include "Facile.h"

class LoadWindow : public QWidget
{
	Q_OBJECT

	public:
		LoadWindow();
		~LoadWindow();

	private slots:
		void EnterFile();
		void Quit();

	private:

		//Layouts
		QVBoxLayout* OverallLayout;

		//Input Filename
		QVBoxLayout* FormLayout;
		QLabel* FileLabel;
		QLineEdit* FileInput;

		//Buttons to Interact with
		QPushButton* QuitButton;
		QPushButton* EnterButton;

		DebuggerWindow* DebugWin;
};
#endif