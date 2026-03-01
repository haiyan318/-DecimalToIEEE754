#include "mainwindow.h"

#include "convertlogic.h"

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
    // createMenuBar();
    tabWidget = new QTabWidget(this);

    // QWidget *centralWidget = new QWidget(this);
    setCentralWidget(tabWidget);

    // 创建单精度标签页
    createSinglePreTab();

    // 创建双精度标签页
    createDoublePreTab();
}

void MainWindow::createSinglePreTab() {
    singlePrecision = new QWidget(this);

    QGridLayout *grid = new QGridLayout(singlePrecision);
    // 标签字体
    QFont labelFont("Microsoft YaHei", 14, QFont::Normal);
    // 文本框字体
    QFont lineEditFont("Microsoft YaHei", 14, QFont::Normal);
    // 按钮字体
    QFont btnFont("Microsoft YaHei", 20, QFont::Normal);

    // ================ ================
    single_labelOfNum1 = new QLabel("数字1:", this);
    single_labelOfNum2 = new QLabel("数字2:", this);

    single_labelOfNum1->setFont(labelFont);
    single_labelOfNum2->setFont(labelFont);
    grid->addWidget(single_labelOfNum1, 0, 0);
    grid->addWidget(single_labelOfNum2, 0, 1);

    single_lineEditOfNum1 = new QLineEdit("");
    single_lineEditOfNum2 = new QLineEdit("");

    single_lineEditOfNum1->setFont(lineEditFont);
    single_lineEditOfNum2->setFont(lineEditFont);
    grid->addWidget(single_lineEditOfNum1, 1, 0);
    grid->addWidget(single_lineEditOfNum2, 1, 1);

    single_binaryExpression1 = new QLabel("数字1的二进制表示:", this);
    single_binaryExpression1->setFont(labelFont);
    grid->addWidget(single_binaryExpression1, 2, 0);
    single_binaryExpression1Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    single_binaryExpression1Content->setReadOnly(true);
    single_binaryExpression1Content->setFont(lineEditFont);
    grid->addWidget(single_binaryExpression1Content, 3, 0);

    single_binaryExpression2 = new QLabel("数字2的二进制表示:", this);
    single_binaryExpression2->setFont(labelFont);
    grid->addWidget(single_binaryExpression2, 2, 1);
    single_binaryExpression2Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    single_binaryExpression2Content->setReadOnly(true);
    single_binaryExpression2Content->setFont(lineEditFont);
    grid->addWidget(single_binaryExpression2Content, 3, 1);

    single_hexExpression1 = new QLabel("数字1的十六进制表示:", this);
    single_hexExpression1->setFont(labelFont);
    grid->addWidget(single_hexExpression1, 4, 0);
    single_hexExpression1Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    single_hexExpression1Content->setReadOnly(true);
    single_hexExpression1Content->setFont(lineEditFont);
    grid->addWidget(single_hexExpression1Content, 5, 0);

    single_hexExpression2 = new QLabel("数字2的十六进制表示:", this);
    single_hexExpression2->setFont(labelFont);
    grid->addWidget(single_hexExpression2, 4, 1);
    single_hexExpression2Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    single_hexExpression2Content->setReadOnly(true);
    single_hexExpression2Content->setFont(lineEditFont);
    grid->addWidget(single_hexExpression2Content, 5, 1);

    single_binaryOfSum = new QLabel("两数和的二进制表示(IEEE 754):", this);
    single_binaryOfSum->setFont(labelFont);
    grid->addWidget(single_binaryOfSum, 6, 0);
    single_binaryOfSumContent = new QLineEdit("", this);
    single_binaryOfSumContent->setReadOnly(true);
    single_binaryOfSumContent->setFont(lineEditFont);
    grid->addWidget(single_binaryOfSumContent, 7, 0);

    single_hexOfSum = new QLabel("两数和的十六进制表示(IEEE 754):", this);
    single_hexOfSum->setFont(labelFont);
    grid->addWidget(single_hexOfSum, 8, 0);
    single_hexOfSumContent = new QLineEdit("", this);
    single_hexOfSumContent->setReadOnly(true);
    single_hexOfSumContent->setFont(lineEditFont);
    grid->addWidget(single_hexOfSumContent, 9, 0);

    single_computeBtn = new QPushButton("计算", this);

    single_computeBtn->setFont(btnFont);
    grid->addWidget(single_computeBtn, 7, 1, 2, 1);

    connect(single_computeBtn, &QPushButton::clicked, this,
            &MainWindow::onSingleComputeClicked);
    // ================ ================

    tabWidget->addTab(singlePrecision, "单精度");
}

void MainWindow::createDoublePreTab() {
    doublePrecision = new QWidget(this);

    QGridLayout *grid = new QGridLayout(doublePrecision);
    // 标签字体
    QFont labelFont("Microsoft YaHei", 14, QFont::Normal);
    // 文本框字体
    QFont lineEditFont("Microsoft YaHei", 14, QFont::Normal);
    // 按钮字体
    QFont btnFont("Microsoft YaHei", 20, QFont::Normal);

    // ================ ================
    double_labelOfNum1 = new QLabel("数字1:", this);
    double_labelOfNum2 = new QLabel("数字2:", this);

    double_labelOfNum1->setFont(labelFont);
    double_labelOfNum2->setFont(labelFont);
    grid->addWidget(double_labelOfNum1, 0, 0);
    grid->addWidget(double_labelOfNum2, 0, 1);

    double_lineEditOfNum1 = new QLineEdit("");
    double_lineEditOfNum2 = new QLineEdit("");

    double_lineEditOfNum1->setFont(lineEditFont);
    double_lineEditOfNum2->setFont(lineEditFont);
    grid->addWidget(double_lineEditOfNum1, 1, 0);
    grid->addWidget(double_lineEditOfNum2, 1, 1);

    double_binaryExpression1 = new QLabel("数字1的二进制表示:", this);
    double_binaryExpression1->setFont(labelFont);
    grid->addWidget(double_binaryExpression1, 2, 0);
    double_binaryExpression1Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    double_binaryExpression1Content->setReadOnly(true);
    double_binaryExpression1Content->setFont(lineEditFont);
    grid->addWidget(double_binaryExpression1Content, 3, 0);

    double_binaryExpression2 = new QLabel("数字2的二进制表示:", this);
    double_binaryExpression2->setFont(labelFont);
    grid->addWidget(double_binaryExpression2, 2, 1);
    double_binaryExpression2Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    double_binaryExpression2Content->setReadOnly(true);
    double_binaryExpression2Content->setFont(lineEditFont);
    grid->addWidget(double_binaryExpression2Content, 3, 1);

    double_hexExpression1 = new QLabel("数字1的十六进制表示:", this);
    double_hexExpression1->setFont(labelFont);
    grid->addWidget(double_hexExpression1, 4, 0);
    double_hexExpression1Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    double_hexExpression1Content->setReadOnly(true);
    double_hexExpression1Content->setFont(lineEditFont);
    grid->addWidget(double_hexExpression1Content, 5, 0);

    double_hexExpression2 = new QLabel("数字2的十六进制表示:", this);
    double_hexExpression2->setFont(labelFont);
    grid->addWidget(double_hexExpression2, 4, 1);
    double_hexExpression2Content = new QLineEdit("", this);
    // 设置文本框不可编辑
    double_hexExpression2Content->setReadOnly(true);
    double_hexExpression2Content->setFont(lineEditFont);
    grid->addWidget(double_hexExpression2Content, 5, 1);

    double_binaryOfSum = new QLabel("两数和的二进制表示(IEEE 754):", this);
    double_binaryOfSum->setFont(labelFont);
    grid->addWidget(double_binaryOfSum, 6, 0);
    double_binaryOfSumContent = new QLineEdit("", this);
    double_binaryOfSumContent->setReadOnly(true);
    double_binaryOfSumContent->setFont(lineEditFont);
    grid->addWidget(double_binaryOfSumContent, 7, 0);

    double_hexOfSum = new QLabel("两数和的十六进制表示(IEEE 754):", this);
    double_hexOfSum->setFont(labelFont);
    grid->addWidget(double_hexOfSum, 8, 0);
    double_hexOfSumContent = new QLineEdit("", this);
    double_hexOfSumContent->setReadOnly(true);
    double_hexOfSumContent->setFont(lineEditFont);
    grid->addWidget(double_hexOfSumContent, 9, 0);

    double_computeBtn = new QPushButton("计算", this);

    double_computeBtn->setFont(btnFont);
    grid->addWidget(double_computeBtn, 7, 1, 2, 1);

    connect(double_computeBtn, &QPushButton::clicked, this,
            &MainWindow::onDoubleComputeClicked);
    // ================ ================

    tabWidget->addTab(doublePrecision, "双精度");
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

/*
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
*/

void MainWindow::onSingleComputeClicked() {
    float decimal1 = single_lineEditOfNum1->text().toFloat();
    float decimal2 = single_lineEditOfNum2->text().toFloat();

    // 得到二进制位
    uint32_t binaryOfDecimale1 = ConvertLogic::floatToBits(decimal1);
    uint32_t binaryOfDecimale2 = ConvertLogic::floatToBits(decimal2);

    QString biTextOfDecimal1 = QString::fromStdString(
        ConvertLogic::formatBinary32(binaryOfDecimale1));
    QString biTextOfDecimal2 = QString::fromStdString(
        ConvertLogic::formatBinary32(binaryOfDecimale2));

    single_binaryExpression1Content->setText(biTextOfDecimal1);
    single_binaryExpression2Content->setText(biTextOfDecimal2);

    QString hexTextOfDecimal1 = QString::fromStdString(
        ConvertLogic::formatHex32(binaryOfDecimale1));
    QString hexTextOfDecimal2 = QString::fromStdString(
        ConvertLogic::formatHex32(binaryOfDecimale2));
    single_hexExpression1Content->setText(hexTextOfDecimal1);
    single_hexExpression2Content->setText(hexTextOfDecimal2);

    float sum = decimal1 + decimal2;
    uint32_t binaryOfSum = ConvertLogic::floatToBits(sum);
    QString biTextOfSum = QString::fromStdString(
        ConvertLogic::formatBinary32(binaryOfSum));
    single_binaryOfSumContent->setText(biTextOfSum);

    uint32_t hexOfSum = binaryOfSum;
    QString hexTextOfSum = QString::fromStdString(
        ConvertLogic::formatHex32(hexOfSum));
    single_hexOfSumContent->setText(hexTextOfSum);
}

void MainWindow::onDoubleComputeClicked() {
    float decimal1 = double_lineEditOfNum1->text().toDouble();
    float decimal2 = double_lineEditOfNum2->text().toDouble();

    // 得到二进制位
    uint64_t binaryOfDecimale1 = ConvertLogic::doubleToBits(decimal1);
    uint64_t binaryOfDecimale2 = ConvertLogic::doubleToBits(decimal2);

    QString biTextOfDecimal1 = QString::fromStdString(
        ConvertLogic::formatBinary64(binaryOfDecimale1));
    QString biTextOfDecimal2 = QString::fromStdString(
        ConvertLogic::formatBinary64(binaryOfDecimale2));

    double_binaryExpression1Content->setText(biTextOfDecimal1);
    double_binaryExpression2Content->setText(biTextOfDecimal2);

    QString hexTextOfDecimal1 = QString::fromStdString(
        ConvertLogic::formatHex64(binaryOfDecimale1));
    QString hexTextOfDecimal2 = QString::fromStdString(
        ConvertLogic::formatHex64(binaryOfDecimale2));
    double_hexExpression1Content->setText(hexTextOfDecimal1);
    double_hexExpression2Content->setText(hexTextOfDecimal2);

    float sum = decimal1 + decimal2;
    uint64_t binaryOfSum = ConvertLogic::floatToBits(sum);
    QString biTextOfSum = QString::fromStdString(
        ConvertLogic::formatBinary64(binaryOfSum));
    double_binaryOfSumContent->setText(biTextOfSum);

    uint64_t hexOfSum = binaryOfSum;
    QString hexTextOfSum = QString::fromStdString(
        ConvertLogic::formatHex64(hexOfSum));
    double_hexOfSumContent->setText(hexTextOfSum);
}
