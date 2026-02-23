#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "convertlogic.h"

class QLabel;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // ************
    // 界面组件
    // ************
    QLabel *labelOfNum1;
    QLabel *labelOfNum2;
    QLineEdit *lineEditOfNum1;
    QLineEdit *lineEditOfNum2;

    QLabel *binaryExpression1;
    QLineEdit *binaryExpression1Content;
    QLabel *binaryExpression2;
    QLineEdit *binaryExpression2Content;
    QLabel *hexExpression1;
    QLineEdit *hexExpression1Content;
    QLabel *hexExpression2;
    QLineEdit *hexExpression2Content;

    QLabel *binaryOfSum;
    QLineEdit *binaryOfSumContent;
    QLabel *hexOfSum;
    QLineEdit *hexOfSumContent;

    QPushButton *computeBtn;

    // ************
    // 成员函数
    // ************
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 初始化界面
    void init();
    void createMenuBar();

    // 展示帮助界面
    void showAboutDialog();

    // “计算”的槽函数
    void onComputeBtnClicked();
};
#endif // MAINWINDOW_H
