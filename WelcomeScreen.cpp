//
// Created by Frank Yang on 2023/8/14.
//

#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::welcomeScreen()
{
    ui->CommandLine->append("WELCOME TO FRACNUT🌰 BY FRANK YANG");
    ui->CommandLine->append("To start using this command-line tool, please be following the following instruction:");

    ui->CommandLine->append("1. Use quit() for quitting the tool;");
    ui->CommandLine->append("2. Use help() for getting help.");

    ui->CommandLine->append("VER. GUI DEV. BETA 1.0.0");

    ui->CommandLine->append("\n");
}
