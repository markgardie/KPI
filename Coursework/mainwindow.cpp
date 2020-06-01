#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Group.h"
#include "Student.h"
#include <istream>
#include <sstream>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int studnum = 0;
int studindex = 0;
QString temp = "";
Group g (30);


void MainWindow::on_AddButton_clicked()
{
    studnum++;
    string name = (ui->NameEdit->text()).toStdString();
    int marks [5];
    double coef = (ui->CoefEdit->text()).toDouble();
    bool budget;

    marks[0] = (ui->M1Edit->text()).toInt();
    marks[1] = (ui->M2Edit->text()).toInt();
    marks[2] = (ui->M3Edit->text()).toInt();
    marks[3] = (ui->M4Edit->text()).toInt();
    marks[4] = (ui->M5Edit->text()).toInt();

    if (ui->BudgetEdit->text() == "так") {
        budget = true;
    }
    else if (ui->BudgetEdit->text() == "ні") {
        budget = false;
    }
    else {
        QMessageBox::critical(this, "Помилка", "Введіть так або ні");
    }

    g.SetAtributes(studindex, name, marks, coef, budget, studnum);

    studindex++;
    QString inputlist = ui->NameEdit->text() + "," +
            ui->M1Edit->text() + "," +
            ui->M2Edit->text() + "," +
            ui->M3Edit->text() + "," +
            ui->M4Edit->text() + "," +
            ui->M5Edit->text() + "," +
            ui->BudgetEdit->text();


    ui->InputList->setText(temp + inputlist + "\n");
    temp = temp + inputlist + "\n";
}

void MainWindow::on_ResetButton_clicked()
{
    ui->InputList->setText("");
    temp = "";
    studnum = 0;
    studindex = 0;
}

void MainWindow::on_RateButton_clicked()
{
   string s1 = g.calcavg();
   QString qs1 = QString::fromStdString(s1);
   ui->AvgList->setText(qs1);

   string s2 = g.sort();
   QString qs2 = QString::fromStdString(s2);
   ui->SortList->setText(qs2);

   string s3 = g.grants();
   QString qs3 = QString::fromStdString(s3);
   ui->RateList->setText(qs3);
}
