#include <QtWidgets>
#include "car.h"

Car car;

class MainWindow : public QMainWindow {
	public:
		MainWindow();
        void xButtonClick();
        void vButtonClick();
        void pButtonClick();
	private:
		QLabel      *textLabel;
        QPushButton *xButton;
        QPushButton *vButton;
        QPushButton *pButton;
		
};

MainWindow :: MainWindow(){
	setFixedSize(600,200);
	setWindowTitle("Test QPushButton v7.2");
	QFont fontLabel("Courier", 18, QFont::Normal);
	QFont fontButton("Times", 18, QFont::Bold);
	
    textLabel = new QLabel("Нажмите на любую кнопку...", this);
	textLabel->setGeometry(0, 0, 400, 50);
	textLabel->setFont(fontLabel);
	
    xButton = new QPushButton("X", this);
    xButton->setGeometry(20, 50, 70, 50);
    xButton->setFont(fontButton);
	
    vButton = new QPushButton("V", this);
    vButton->setGeometry(110, 50, 70, 50);
    vButton->setFont(fontButton);
	
    pButton = new QPushButton("P", this);
    pButton->setGeometry(200, 50, 70, 50);
    pButton->setFont(fontButton);
	
    connect(xButton, &QPushButton::clicked,
            this, &MainWindow::xButtonClick);
    connect(vButton, &QPushButton::clicked,
            this, &MainWindow::vButtonClick);
    connect(pButton, &QPushButton::clicked,
            this, &MainWindow::pButtonClick);
			
}

void MainWindow::xButtonClick(){
    textLabel->setText("X = " + QString::number(car.x));
}

void MainWindow::vButtonClick(){
    textLabel->setText("V = " + QString::number(car.v));
}

void MainWindow::pButtonClick(){
    textLabel->setText("P = " + QString::number(car.p));
}

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
	
}
