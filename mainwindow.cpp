#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow() {}

void MainWindow::init() {
    resize(880, 580);
    setWindowTitle("DecimalToIEEE754");
    createMenuBar();

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QGridLayout *grid = new QGridLayout(centralWidget);

    labelOfNum1 = new QLabel("数字1:", this);
    labelOfNum2 = new QLabel("数字2:", this);
    // 标签字体
    QFont labelFont("Microsoft YaHei", 14, QFont::Normal);
    labelOfNum1->setFont(labelFont);
    labelOfNum2->setFont(labelFont);
    grid->addWidget(labelOfNum1, 0, 0);
    grid->addWidget(labelOfNum2, 0, 1);

    lineEditOfNum1 = new QLineEdit("");
    lineEditOfNum2 = new QLineEdit("");
    // 文本框字体
    QFont lineEditFont("Microsoft YaHei", 14, QFont::Normal);
    lineEditOfNum1->setFont(lineEditFont);
    lineEditOfNum2->setFont(lineEditFont);
    grid->addWidget(lineEditOfNum1, 1, 0);
    grid->addWidget(lineEditOfNum2, 1, 1);

    binaryExpression1 = new QLabel("数字1的二进制表示:", this);
    binaryExpression1->setFont(labelFont);
    grid->addWidget(binaryExpression1, 2, 0);
    binaryExpression1Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    binaryExpression1Content->setReadOnly(true);
    binaryExpression1Content->setFont(lineEditFont);
    grid->addWidget(binaryExpression1Content, 3, 0);

    binaryExpression2 = new QLabel("数字2的二进制表示:", this);
    binaryExpression2->setFont(labelFont);
    grid->addWidget(binaryExpression2, 2, 1);
    binaryExpression2Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    binaryExpression2Content->setReadOnly(true);
    binaryExpression2Content->setFont(lineEditFont);
    grid->addWidget(binaryExpression2Content, 3, 1);

    hexExpression1 = new QLabel("数字1的十六进制表示:", this);
    hexExpression1->setFont(labelFont);
    grid->addWidget(hexExpression1, 4, 0);
    hexExpression1Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    hexExpression1Content->setReadOnly(true);
    hexExpression1Content->setFont(lineEditFont);
    grid->addWidget(hexExpression1Content, 5, 0);

    hexExpression2 = new QLabel("数字2的十六进制表示:", this);
    hexExpression2->setFont(labelFont);
    grid->addWidget(hexExpression2, 4, 1);
    hexExpression2Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    hexExpression2Content->setReadOnly(true);
    hexExpression2Content->setFont(lineEditFont);
    grid->addWidget(hexExpression2Content, 5, 1);

    binaryOfSum = new QLabel("两数和的二进制表示(IEEE 754):", this);
    binaryOfSum->setFont(labelFont);
    grid->addWidget(binaryOfSum, 6, 0);
    binaryOfSumContent = new QLineEdit("", this);
    binaryOfSumContent->setReadOnly(true);
    binaryOfSumContent->setFont(lineEditFont);
    grid->addWidget(binaryOfSumContent, 7, 0);

    hexOfSum = new QLabel("两数和的十六进制表示(IEEE 754):", this);
    hexOfSum->setFont(labelFont);
    grid->addWidget(hexOfSum, 8, 0);
    hexOfSumContent = new QLineEdit("", this);
    hexOfSumContent->setReadOnly(true);
    hexOfSumContent->setFont(lineEditFont);
    grid->addWidget(hexOfSumContent, 9, 0);

    computeBtn = new QPushButton("计算", this);
    QFont btnFont("Microsoft YaHei", 20, QFont::Normal);
    computeBtn->setFont(btnFont);
    grid->addWidget(computeBtn, 7, 1, 2, 1);

    // “计算”按钮的信号槽连接
    connect(computeBtn, &QPushButton::clicked, this, &MainWindow::onComputeBtnClicked);
}

void MainWindow::createMenuBar() {
    // 获取菜单栏（QMainWindow 自带，不用 new）
    QMenuBar *menuBar = this->menuBar();

    // ===== 创建菜单 =====
    // 文件菜单
    QMenu *moduleMenu = menuBar->addMenu("模式");

    // 帮助菜单
    QMenu *helpMenu = menuBar->addMenu("帮助");

    // ===== 创建菜单项 =====
    // 文件菜单项
    QAction *toIEEE754Action = moduleMenu->addAction("IEEE754");

    moduleMenu->addSeparator();  // 添加分隔线

    QAction *integerAction = moduleMenu->addAction("IntegerToBinary");

    moduleMenu->addSeparator();  // 添加分隔线

    QAction *exitAction = moduleMenu->addAction("退出");
    exitAction->setShortcut(QKeySequence::Quit);

    // 帮助菜单项
    QAction *aboutAction = helpMenu->addAction("关于");
    aboutAction->setShortcut(QKeySequence::HelpContents);

    // ===== 连接信号槽 =====
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutDialog);
}

void MainWindow::showAboutDialog() {
    // // QMessageBox::about(this,
    //                    "关于浮点数及其对应IEEE 754表示的转换工具",
    //                    "一个简单小工具，可以将一个小数转换为其在IEEE 754标准下对应的机器数\n版本 1.0\n使用 Qt 开发");

    // QMessageBox msgBox(this);
    // msgBox.setWindowTitle("关于");  // 短标题，能完整显示
    // msgBox.setText("浮点数及其对应 IEEE 754 表示的转换工具");  // 主标题（大字体）
    // msgBox.setInformativeText("简单小工具\n版本 1.0\n使用 Qt 开发");  // 详细信息
    // msgBox.setIcon(QMessageBox::Information);
    // msgBox.setStandardButtons(QMessageBox::Ok);
    // msgBox.exec();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("关于");

    // 使用 HTML 格式化内容
    msgBox.setText("<h2>浮点数 ↔ IEEE 754 转换工具</h2>");
    msgBox.setInformativeText(
        "<p>一个简单的小工具，用于十进制浮点数与 IEEE 754 二进制表示之间的转换。</p>"
        "<p><b>版本：</b>1.0</p>"
        "<p><b>开发框架：</b>Qt 6.8.3</p>"
        "<p><a href='#'>GitHub 项目主页</a></p>"
        );

    msgBox.setIconPixmap(QPixmap(":/icons/app-icon.png").scaled(64, 64));  // 自定义图标
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::onComputeBtnClicked() {
    float decimal1 = lineEditOfNum1->text().toFloat();
    float decimal2 = lineEditOfNum2->text().toFloat();

    // 得到二进制位
    uint32_t binaryOfDecimale1 = ConvertLogic::floatToBits(decimal1);
    uint32_t binaryOfDecimale2 = ConvertLogic::floatToBits(decimal2);

    QString biTextOfDecimal1 = QString::fromStdString(ConvertLogic::formatBinary32(binaryOfDecimale1));
    QString biTextOfDecimal2 = QString::fromStdString(ConvertLogic::formatBinary32(binaryOfDecimale2));

    binaryExpression1Content->setText(biTextOfDecimal1);
    binaryExpression2Content->setText(biTextOfDecimal2);

    QString hexTextOfDecimal1 = QString::fromStdString(ConvertLogic::formatHex32(binaryOfDecimale1));
    QString hexTextOfDecimal2 = QString::fromStdString(ConvertLogic::formatHex32(binaryOfDecimale2));
    hexExpression1Content->setText(hexTextOfDecimal1);
    hexExpression2Content->setText(hexTextOfDecimal2);

    float sum = decimal1 + decimal2;
    uint32_t binaryOfSum = ConvertLogic::floatToBits(sum);
    QString biTextOfSum = QString::fromStdString(ConvertLogic::formatBinary32(binaryOfSum));
    binaryOfSumContent->setText(biTextOfSum);

    uint32_t hexOfSum = binaryOfSum;
    QString hexTextOfSum = QString::fromStdString(ConvertLogic::formatHex32(hexOfSum));
    hexOfSumContent->setText(hexTextOfSum);
}
