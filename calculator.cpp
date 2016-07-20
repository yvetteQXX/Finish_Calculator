#include "calculator.h"

//#include <QtWidgets/qlineedit.h>
//#include <QtWidgets/qlayout.h>
//#include <QtWidgets/qwhatsthis.h>
//#include <QtWidgets/qheaderview.h>
#include <cmath>

Calculator::Calculator(QWidget *parent)
	: QDialog(parent)
{
	num1 = 0;
	num2 = 0;
	ans = 0;
	symbol = true;
	mark = 1;
	S = "";

	lineEditor = new QLineEdit("0");
	one = new QPushButton(tr("1"));
	two = new QPushButton(tr("2"));
	three = new QPushButton(tr("3"));
	four = new QPushButton(tr("4"));
	five = new QPushButton(tr("5"));
	six = new QPushButton(tr("6"));
	seven = new QPushButton(tr("7"));
	eight = new QPushButton(tr("8"));
	nine = new QPushButton(tr("9"));
	zero = new QPushButton(tr("0"));
	newcalcu = new QPushButton(tr("C"));
	add = new QPushButton(tr("+"));
	minus = new QPushButton(tr("-"));
	multiplay = new QPushButton(tr("*"));
	divide = new QPushButton(tr("/"));
	getanswer = new QPushButton(tr("="));
	point = new QPushButton(tr("."));
	dele = new QPushButton(tr("AC"));
	unknown = new QPushButton(tr("+/-"));

	lineEditor->setFixedSize(170,30);
	one->setFixedSize(35, 35);
	two->setFixedSize(35, 35);
	three->setFixedSize(35, 35);
	four->setFixedSize(35, 35);
	five->setFixedSize(35, 35);
	six->setFixedSize(35, 35);
	seven->setFixedSize(35, 35);
	eight->setFixedSize(35, 35);
	nine->setFixedSize(35, 35);
	zero->setFixedSize(35, 35);
	newcalcu->setFixedSize(35, 35);
	add->setFixedSize(35, 35);
	minus->setFixedSize(35, 35);
	multiplay->setFixedSize(35, 35);
	divide->setFixedSize(35, 35);
	getanswer->setFixedSize(80, 35);
	point->setFixedSize(35, 35);
	dele->setFixedSize(35, 35);
	unknown->setFixedSize(35, 35);

	connect(one, SIGNAL(clicked()), this,SLOT(button_one_clicked()));
	connect(two, SIGNAL(clicked()), this, SLOT(button_two_clicked()));
	connect(three, SIGNAL(clicked()), this, SLOT(button_three_clicked()));
	connect(four, SIGNAL(clicked()), this, SLOT(button_four_clicked()));
	connect(five, SIGNAL(clicked()), this, SLOT(button_five_clicked()));
	connect(six, SIGNAL(clicked()), this, SLOT(button_six_clicked()));
	connect(seven, SIGNAL(clicked()), this, SLOT(button_seven_clicked()));
	connect(eight, SIGNAL(clicked()), this, SLOT(button_eight_clicked()));
	connect(nine, SIGNAL(clicked()), this, SLOT(button_nine_clicked()));
	connect(zero, SIGNAL(clicked()), this, SLOT(button_zero_clicked()));
	connect(point, SIGNAL(clicked()), this, SLOT(button_point_clicked()));
	connect(minus, SIGNAL(clicked()), this, SLOT(button_minus_clicked()));
	connect(add, SIGNAL(clicked()), this, SLOT(button_add_clicked()));
	connect(multiplay, SIGNAL(clicked()), this, SLOT(button_multiplay_clicked()));
	connect(divide, SIGNAL(clicked()), this, SLOT(button_divide_clicked()));
	connect(getanswer, SIGNAL(clicked()), this, SLOT(button_getanswer_clicked()));
	connect(dele, SIGNAL(clicked()), this, SLOT(close()));
	connect(unknown, SIGNAL(clicked()), this, SLOT(button_unknown_clicked()));
	connect(newcalcu, SIGNAL(clicked()), this, SLOT(button_newcalcu_clicked()));

	QHBoxLayout *titleLayout = new QHBoxLayout;
	titleLayout->addWidget(lineEditor);

	QHBoxLayout *firstLayout = new QHBoxLayout;
	firstLayout->addWidget(dele);
	firstLayout->addWidget(newcalcu);
	firstLayout->addWidget(unknown);
	firstLayout->addWidget(divide);

	QHBoxLayout *secondLayout = new QHBoxLayout;
	secondLayout->addWidget(seven);
	secondLayout->addWidget(eight);
	secondLayout->addWidget(nine);
	secondLayout->addWidget(multiplay);

	QHBoxLayout *thirdLayout = new QHBoxLayout;
	thirdLayout->addWidget(four);
	thirdLayout->addWidget(five);
	thirdLayout->addWidget(six);
	thirdLayout->addWidget(minus);

	QHBoxLayout *fourthLayout = new QHBoxLayout;
	fourthLayout->addWidget(one);
	fourthLayout->addWidget(two);
	fourthLayout->addWidget(three);
	fourthLayout->addWidget(add);

	QHBoxLayout *fithLayout = new QHBoxLayout;
	fithLayout->addWidget(zero);
	fithLayout->addWidget(point);
	fithLayout->addWidget(getanswer);


	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(titleLayout);
	mainLayout->addLayout(firstLayout);
	mainLayout->addLayout(secondLayout);
	mainLayout->addLayout(thirdLayout);
	mainLayout->addLayout(fourthLayout);
	mainLayout->addLayout(fithLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("CALCULATOR"));
	setFixedHeight(sizeHint().height());
	//setAutoFillBackground(true);
	//setFixedHeight();
	//setFixedWidth();
}

void Calculator::button_zero_clicked()
{
	S += "0";
	lineEditor->setText(S);
	if (mark == 1) num1 = num1 * 10 + 0;
	else num2 = num2 * 10;
}

void Calculator::button_one_clicked()
{
	S += "1";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol) {
			num1 = num1 * 10 + 1; 
		}
		else{ 
			num1 = num1 * 10 - 1; 
		}
	}
	else{
		if (symbol){ 
			num2 = num2 * 10 + 1; 
		}
		else{ 
			num2 = num2 * 10 - 1; 
		}
	}
}

void Calculator::button_two_clicked()
{
	S += "2";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol) { 
			num1 = num1 * 10 + 2; 
		}
		else{ 
			num1 = num1 * 10 - 2; 
		}
	}
	else{
		if (symbol){ 
			num2 = num2 * 10 + 2; 
		}
		else{ 
			num2 = num2 * 10 - 2; 
		}
	}
}

void Calculator::button_three_clicked()
{
	S += "3";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol) { 
			num1 = num1 * 10 + 3; 
		}
		else{ 
			num1 = num1 * 10 - 3; 
		}
	}
	else{
		if (symbol){
			num2 = num2 * 10 + 3;
		}
		else{
			num2 = num2 * 10 - 3;
		}
	}
}

void Calculator::button_four_clicked()
{
	S += "4";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol){
			num1 = num1 * 10 + 4;
		}
		else{
			num1 = num1 * 10 - 4;
		}
	}
	else{
		if (symbol){
			num2 = num2 * 10 + 4;
		}
		else{
			num2 = num2 * 10 - 4;
		}
	}
}

void Calculator::button_five_clicked()
{
	S += "5";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol){
			num1 = num1 * 10 + 5;
		}
		else{
			num1 = num1 * 10 - 5;
		}
	}
	else{
		if (symbol){
			num2 = num2 * 10 + 5;
		}
		else{
			num2 = num2 * 10 - 5;
		}
	}
}

void Calculator::button_six_clicked()
{
	S += "6";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol) {
			num1 = num1 * 10 + 6;
		}
		else{
			num1 = num1 * 10 - 6;
		}
	}
	else{
		if (symbol){
			num2 = num2 * 10 + 6;
		}
		else{
			num2 = num2 * 10 - 6;
		}
	}
}

void Calculator::button_seven_clicked()
{
	S += "7";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol) {
			num1 = num1 * 10 + 7;
		}
		else{
			num1 = num1 * 10 - 7;
		}
	}
	else{
		if (symbol){
			num2 = num2 * 10 + 7;
		}
		else{
			num2 = num2 * 10 - 7;
		}
	}
}

void Calculator::button_eight_clicked()
{
	S += "8";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol) {
			num1 = num1 * 10 + 8;
		}
		else{
			num1 = num1 * 10 - 8;
		}
	}
	else{
		if (symbol){
			num2 = num2 * 10 + 8;
		}
		else{
			num2 = num2 * 10 - 8;
		}
	}
}

void Calculator::button_nine_clicked()
{
	S += "9";
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol) {
			num1 = num1 * 10 + 9;
		}
		else{
			num1 = num1 * 10 - 9;
		}
	}
	else{
		if (symbol){
			num2 = num2 * 10 + 9;
		}
		else{
			num2 = num2 * 10 - 9;
		}
	}
}


void Calculator::button_add_clicked()
{
	S += "+";
	mathsymbol = '+';
	lineEditor->setText(S);
	symbol = true;
	mark = 2;
}

void Calculator::button_minus_clicked()
{
	S += "-";
	mathsymbol = '-';
	lineEditor->setText(S);
	symbol = true;
	mark = 2;
}

void Calculator::button_divide_clicked()
{
	S += "/";
	mathsymbol = '/';
	lineEditor->setText(S);
	symbol = true;
	mark = 2;
}

void Calculator::button_multiplay_clicked()
{
	S += "*";
	mathsymbol = '*';
	lineEditor->setText(S);
	symbol = true;
	mark = 2;
}

void Calculator::button_getanswer_clicked()
{
	S += "=";
	switch (mathsymbol)
	{
	case '+': ans = num1 + num2; break;
	case '-': ans = num1-num2; break;
	case '*':ans = num1*num2; break;
	case '/':if(num2) ans = num1 / num2; break;
	}
	int i = 0;
	int result = ans;
	QString s;
	while (result)
	{
		i++;
		result /= 10;
	}
	for (; i; i--)
	{
		S+= (ans / (int)pow(10, i - 1)+'0');
		ans %= (int)pow(10, i - 1);
	}
	lineEditor->setText(S);
	symbol = true;
	num1 = num2 = 0;
	mark = 1;
	S = "";
}


void Calculator::button_unknown_clicked()
{
	S += "-";
	lineEditor->setText(S);
	symbol = false;
}

void Calculator::button_newcalcu_clicked()
{
	S = "";
	lineEditor->setText(tr("0"));
	num1 = 0;
	num2 = 0;
	ans = 0;
	symbol = true;
	mark = 1;
}

void Calculator::button_point_clicked()
{

}

//void Calculator::button_dele_clicked()
//{
//}


Calculator::~Calculator()
{

}