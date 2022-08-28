#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setEnable(){
    ui->coffee->setEnabled(true);
    ui->milk->setEnabled(true);
    ui->mango->setEnabled(true);
}

void Widget::changeMoney(int diff)
{
    setEnable();
    money += diff;
    if (money < 100)
        ui->coffee->setEnabled(false);
    if (money < 150)
        ui->milk->setEnabled(false);
    if (money < 200)
        ui->mango->setEnabled(false);
}


void Widget::on_pb500_clicked()
{
    this->changeMoney(500);
    ui->lcdNumber->display(money);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    ui->lcdNumber->display(money);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    ui->lcdNumber->display(money);
}


void Widget::on_coffee_clicked()
{
    changeMoney(-100);
    ui->lcdNumber->display(money);

}

void Widget::on_milk_clicked()
{
    changeMoney(-150);
    ui->lcdNumber->display(money);
}

void Widget::on_mango_clicked()
{
    changeMoney(-200);
    ui->lcdNumber->display(money);
}

void Widget::on_reset_clicked()
{
    //resets
    int fhund = money/500;
    money= money%500;
    int hund = money/100;
    money= money%100;
    int fifty = money/50;
    money= money%50;
    int ten = money/10;
    money= money%10;

    char s1[100];
    char s2[10];
    char s3[10];
    char s4[10];
    char s5[10]=" /";
    sprintf(s1, "%d",fhund);
    sprintf(s2, "%d",hund);
    sprintf(s3, "%d",fifty);
    sprintf(s4, "%d",ten);
    strcat(s1,s5);
    strcat(s2,s5);
    strcat(s3,s5);

    strcat(s1,s2);
    strcat(s1,s3);
    strcat(s1,s4);
    QMessageBox::about(this,"남은 잔액[순서대로 500,100,50,10 갯수입니다.]",s1);

}
