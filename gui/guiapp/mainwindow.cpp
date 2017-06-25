#include <memory>
#include <QString>
#include <QTableWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QTableWidget* table = ui->tableWidget;
    table->setRowCount(tableSize);
    table->setColumnCount(tableSize);
    for (auto i=0; i < tableSize*tableSize; i++) {
        auto* itemptr = new QTableWidgetItem(QString::number(i));
        table->setItem(i/tableSize, i%tableSize, itemptr);
        itemPtrs[i] = itemptr;
    }
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
}

MainWindow::~MainWindow() {
    delete ui;
    for(auto& i : itemPtrs) {
        delete i;
    }
}
