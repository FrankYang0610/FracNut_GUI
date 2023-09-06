#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "StringConvertor.cpp"
#include "Parser.cpp"
#include "Helper.cpp"
#include <cstring>

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

void MainWindow::inputCountOutput()
{
    ui->CommandLine->insertPlainText("Input");
    ui->CommandLine->insertPlainText("[");
    ui->CommandLine->insertPlainText(unsignedIntConvert(this->inputCount));
    ui->CommandLine->insertPlainText("]");
    ui->CommandLine->insertPlainText(":");
    ui->CommandLine->insertPlainText(" ");
}

void MainWindow::outputCountOutput()
{
    ui->CommandLine->insertPlainText("Output");
    ui->CommandLine->insertPlainText("[");
    ui->CommandLine->insertPlainText(unsignedIntConvert(this->inputCount));
    ui->CommandLine->insertPlainText("]");
    ui->CommandLine->insertPlainText(":");
    ui->CommandLine->insertPlainText(" ");
}

void MainWindow::inputBackspace()
{
    currentInput = currentInput.substr(0, currentInput.size() - 1);
}

void MainWindow::forResult()
{
    // PROCESS THE CURRENT CALCULATION
    std::string parsed = parse(currentInput);

    if (parsed == "quit()")
    {}

    else if (parsed == "help()")
        getHelp();

    else if (parsed == "lastResult()")
        ui->CommandLine->append(stringConvert(this->lastResult));

    else if (parsed == "clipboard()")
        ui->CommandLine->append(stringConvert(this->clipboard));

    else if (parsed == "copy(lastResult())")
    {
        clipboard = lastResult;
        ui->CommandLine->append("Copied.");
    }

    else if (parsed == "remove(clipboard())")
    {
        clipboard = "0";
        ui->CommandLine->append("Removed.\n");
    }

    else if (parsed == "remove(lastResult())")
    {
        lastResult = "0";
        ui->CommandLine->append("Removed.");
    }

    else // EXPRESSION
    {
        outputCountOutput();
        ui->CommandLine->insertPlainText(stringConvert(parsed));
    }

    // PREPARE FOR NEW CALCULATION
    this->inputCount ++;
    this->currentInput = "";
    ui->CommandLine->insertPlainText("\n\n");
    inputCountOutput();
}

void MainWindow::on_Keypad1_clicked()
{
    ui->CommandLine->insertPlainText("1");
    this->currentInput += '1';
}


void MainWindow::on_Keypad2_clicked()
{
    ui->CommandLine->insertPlainText("2");
    this->currentInput += '2';
}


void MainWindow::on_Keypad3_clicked()
{
    ui->CommandLine->insertPlainText("3");
    this->currentInput += '3';
}


void MainWindow::on_Keypad4_clicked()
{
    ui->CommandLine->insertPlainText("4");
    this->currentInput += '4';
}


void MainWindow::on_Keypad5_clicked()
{
    ui->CommandLine->insertPlainText("5");
    this->currentInput += '5';
}


void MainWindow::on_Keypad6_clicked()
{
    ui->CommandLine->insertPlainText("6");
    this->currentInput += '6';
}


void MainWindow::on_Keypad7_clicked()
{
    ui->CommandLine->insertPlainText("7");
    this->currentInput += '7';
}


void MainWindow::on_Keypad8_clicked()
{
    ui->CommandLine->insertPlainText("8");
    this->currentInput += '8';
}


void MainWindow::on_Keypad9_clicked()
{
    ui->CommandLine->insertPlainText("9");
    this->currentInput += '9';
}


void MainWindow::on_Keypad0_clicked()
{
    ui->CommandLine->insertPlainText("0");
    this->currentInput += '0';
}


void MainWindow::on_KeypadLeftBracket_clicked()
{
    ui->CommandLine->insertPlainText("[");
    this->currentInput += '[';
}


void MainWindow::on_KeypadRightBracket_clicked()
{
    ui->CommandLine->insertPlainText("]");
    this->currentInput += ']';
}


void MainWindow::on_KeypadDot_clicked()
{
    ui->CommandLine->insertPlainText(".");
    this->currentInput += '.';
}


void MainWindow::on_KeypadPlus_clicked()
{
    ui->CommandLine->insertPlainText("+");
    this->currentInput += '+';
}


void MainWindow::on_KeypadMinus_clicked()
{
    ui->CommandLine->insertPlainText("-");
    this->currentInput += '-';
}


void MainWindow::on_KeypadMultiply_clicked()
{
    ui->CommandLine->insertPlainText("*");
    this->currentInput += '*';
}


void MainWindow::on_KeypadDivide_clicked()
{
    ui->CommandLine->insertPlainText("/");
    this->currentInput += '/';
}

void MainWindow::on_KeypadCalculate_clicked()
{
    ui->CommandLine->insertPlainText("\n");

    // CALCULATE & PROCESSING
    forResult();
}



void MainWindow::on_CommandLine_textChanged()
{

}


void MainWindow::on_KeypadBackspace_clicked()
{
    // For TextEdit
    QTextCursor cursor = ui->CommandLine->textCursor();
    cursor.movePosition(QTextCursor::End);
    cursor.deletePreviousChar();

    // For String
    inputBackspace();
}


void MainWindow::on_KeypadClear_clicked()
{
    ui->CommandLine->clear();

    this->currentInput = "";
    inputCountOutput();
}


void MainWindow::on_KeypadLeftParentheses_clicked()
{
    ui->CommandLine->insertPlainText("(");
    this->currentInput += '(';
}


void MainWindow::on_KeypadRightparentheses_clicked()
{
    ui->CommandLine->insertPlainText(")");
    this->currentInput += ')';
}

