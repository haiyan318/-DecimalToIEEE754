#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // 界面容器
    QTabWidget *tabWidget;
    QWidget *singlePrecision;
    QWidget *doublePrecision;

    // 单精度专属
    QLabel *single_labelOfNum1;
    QLabel *single_labelOfNum2;
    QLineEdit *single_lineEditOfNum1;
    QLineEdit *single_lineEditOfNum2;

    QLabel *single_binaryExpression1;
    QLineEdit *single_binaryExpression1Content;
    QLabel *single_binaryExpression2;
    QLineEdit *single_binaryExpression2Content;
    QLabel *single_hexExpression1;
    QLineEdit *single_hexExpression1Content;
    QLabel *single_hexExpression2;
    QLineEdit *single_hexExpression2Content;

    QLabel *single_binaryOfSum;
    QLineEdit *single_binaryOfSumContent;
    QLabel *single_hexOfSum;
    QLineEdit *single_hexOfSumContent;

    QPushButton *single_computeBtn;

    // 双精度专属
    QLabel *double_labelOfNum1;
    QLabel *double_labelOfNum2;
    QLineEdit *double_lineEditOfNum1;
    QLineEdit *double_lineEditOfNum2;

    QLabel *double_binaryExpression1;
    QLineEdit *double_binaryExpression1Content;
    QLabel *double_binaryExpression2;
    QLineEdit *double_binaryExpression2Content;
    QLabel *double_hexExpression1;
    QLineEdit *double_hexExpression1Content;
    QLabel *double_hexExpression2;
    QLineEdit *double_hexExpression2Content;

    QLabel *double_binaryOfSum;
    QLineEdit *double_binaryOfSumContent;
    QLabel *double_hexOfSum;
    QLineEdit *double_hexOfSumContent;

    QPushButton *double_computeBtn;


    // 成员函数
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 初始化界面
    void init();
    void createSinglePreTab();
    void createDoublePreTab();
    void createMenuBar();
    // 展示帮助界面
    void showAboutDialog();

    // “计算”的槽函数
    void onSingleComputeClicked();
    void onDoubleComputeClicked();
};
#endif // MAINWINDOW_H
