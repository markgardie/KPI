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
    string m1 = (ui->M1Edit->text()).toStdString();
    string m2 = (ui->M2Edit->text()).toStdString();
    string m3 = (ui->M3Edit->text()).toStdString();
    string m4 = (ui->M4Edit->text()).toStdString();
    string m5 = (ui->M5Edit->text()).toStdString();
    string budget = (ui->BudgetEdit->text()).toStdString();
    double coef = (ui->CoefEdit->text()).toDouble();

    if (budget == "так" || budget == "ні") {
        g.SetAtributes(studindex, name, m1, m2, m3, m4, m5, budget, coef, studnum);
        studindex++;
        QString inputlist = ui->NameEdit->text() + "," +
                ui->M1Edit->text() + "," +
                ui->M2Edit->text() + "," +
                ui->M3Edit->text() + "," +
                ui->M4Edit->text() + "," +
                ui->M5Edit->text() + "," +
                ui->BudgetEdit->text();


        ui->InputList->setText(inputlist + "\n" + temp);
        temp = inputlist + "\n" + temp;
    }
    else {
        QMessageBox::critical(this, "Помилка", "Введіть так або ні");
    }

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
