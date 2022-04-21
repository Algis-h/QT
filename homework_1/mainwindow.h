#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QTcore/qmath.h>
#include <QFile>
#include <QDoubleValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calqulate_qe_clicked();

    void on_calculate_ct_clicked();

    void on_add_text_clicked();

    void on_replace_text_clicked();

    void on_insert_html_clicked();

private:
    Ui::MainWindow *ui;
    void set_style_sheet();
};
#endif // MAINWINDOW_H
