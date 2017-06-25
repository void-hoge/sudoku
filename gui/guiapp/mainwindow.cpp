#include <qtablewidget.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace {
    constexpr int tableSize = 16;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QTableWidget* table = ui->tableWidget;
    table->setRowCount(tableSize);
    table->setColumnCount(tableSize);
}

MainWindow::~MainWindow() {
    delete ui;
}
