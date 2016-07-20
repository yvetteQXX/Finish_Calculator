#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtWidgets>
//#include <QtWidgets/QMainWindow>
//#include <QtWidgets/qlineedit.h>
//#include <QtWidgets/qpushbutton.h>

//class QPushButton;
//class LineEdit;

class Calculator : public QDialog
{
	Q_OBJECT

public:
	Calculator(QWidget *parent = 0);
	~Calculator();

private slots:
	void button_one_clicked();
	void button_two_clicked();
	void button_three_clicked();
	void button_four_clicked();
	void button_five_clicked();
	void button_six_clicked();
	void button_seven_clicked();
	void button_eight_clicked();
	void button_nine_clicked();
	void button_zero_clicked();
	void button_getanswer_clicked();
	void button_add_clicked();
	void button_minus_clicked();
	void button_multiplay_clicked();
	void button_divide_clicked();
	void button_point_clicked();
	void button_unknown_clicked();
	void button_newcalcu_clicked();
	//void button_dele_clicked();

 signals:
	void findClicked();

private:
	QLineEdit *lineEditor;
	QPushButton *getanswer;
	QPushButton *one;
	QPushButton *two;
	QPushButton *three;
	QPushButton *four;
	QPushButton *five;
	QPushButton *six;
	QPushButton *seven;
	QPushButton *eight;
	QPushButton *nine;
	QPushButton *zero;
	QPushButton *dele;
	QPushButton *add;
	QPushButton *minus;
	QPushButton *divide;
	QPushButton *multiplay;
	QPushButton *point;
	QPushButton *unknown;
	QPushButton *newcalcu;
	int num1, num2, ans;
	bool symbol;
	char mathsymbol;
	int mark;
	QString S;

};

#endif // CALCULATOR_H
