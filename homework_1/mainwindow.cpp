#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->coef_a->setValidator(new QDoubleValidator());
    ui->coef_b->setValidator(new QDoubleValidator());
    ui->coef_c->setValidator(new QDoubleValidator());

    ui->side1->setValidator(new QDoubleValidator());
    ui->side2->setValidator(new QDoubleValidator());
    ui->angle->setValidator(new QDoubleValidator());
    set_style_sheet();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_style_sheet()
{
    QFile file("../theme/darkorange.qss");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString theme = file.readAll();
    setStyleSheet(theme);

}


void MainWindow::on_calqulate_qe_clicked()
{
    QLocale loc(QLocale::system());

    if(ui->coef_a->text().isEmpty() || ui->coef_b->text().isEmpty() || ui->coef_c->text().isEmpty())
    {
        ui->result_qe->setText("Коэффициенты пустые");
        return;
    }

    double a = loc.toDouble(ui->coef_a->text());
    double b = loc.toDouble(ui->coef_b->text());
    double c = loc.toDouble(ui->coef_c->text());

    double discriminant = (b * b) - 4 * a * c;


    if(a == 0 && b != 0)
    {
        ui->result_qe->setText("X = " + QString::number(-c/b));


    }
    else if(discriminant < 0)
    {
        ui->result_qe->setText("Корней нет");

    }
    else if(discriminant == 0)
    {
        ui->result_qe->setText("X = " + QString::number(-b/(2 * a)));
        std::cout << "X =  " << -b/(2 * a) << std::endl;

    }
    else
    {
        QString x1 = "X1 = " + QString::number((-b - qSqrt(discriminant))/(2 * a));
        QString x2 = "X2 = " + QString::number((-b - qSqrt(discriminant))/(2 * a));

        ui->result_qe->setText(x1 + "\t" + x2);

    }


//    result->setText("QString::number(a)");
//    result->show();
    std::cout << "Button: " << discriminant << std::endl;
}


void MainWindow::on_calculate_ct_clicked()
{
    QLocale loc(QLocale::system());

    if(ui->side1->text().isEmpty() || ui->side2->text().isEmpty() || ui->angle->text().isEmpty())
    {
        ui->result_ct->setText("Поля пустые");
        return;
    }

    double side1 = loc.toDouble(ui->side1->text());
    double side2 = loc.toDouble(ui->side2->text());
    double angle = loc.toDouble(ui->angle->text());

    if(ui->degrees->isChecked())
    {
        angle = qDegreesToRadians(angle);
        std::cout << "Angle: " << angle << std::endl;
    }

    ui->result_ct->setText(QString::number(qSqrt((qPow(side1, 2) + qPow(side2, 2)) - 2 * side1 * side2 * qCos(angle))));

}


void MainWindow::on_add_text_clicked()
{
    QString left = ui->left_text->toPlainText();
    ui->right_text->append(left);
}


void MainWindow::on_replace_text_clicked()
{
    QString left = ui->left_text->toPlainText();
    ui->right_text->setPlainText(left);
}


void MainWindow::on_insert_html_clicked()
{
    QString left = "QString left";
    ui->right_text->setHtml("<font color='red'>Hello</font>");
}

