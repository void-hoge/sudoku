#include <memory>
#include <QString>
#include <QTableWidget>
#include "qtablewidgetcontroller.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "debugwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), board{ } {
    ui->setupUi(this);
    connect(ui->actionSwitch_debug_mode, SIGNAL(triggered()), this, SLOT(switch_debug_mode()));

    // init member
    table = ui->tableWidget;
    // check
    if (table == nullptr) std::runtime_error("Couldn't ui components on MainWindow.");

    // init widgets
    table->setRowCount(eachside);
    table->setColumnCount(eachside);
    QTableWidgetItemAdapter controller(*table);
    auto itr = controller.begin();
    for (auto& i : board.checked_array()) {
        *itr = QTableWidgetItem(i == -1 ? " " : QString::number(i));
        ++itr;
    }
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(table, SIGNAL(cellClicked(int,int)), this, SLOT(cell_clicked(int, int)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    (void)event; // suppress unused parameter warning
    if (debugWindow != nullptr) debugWindow->close();
}

void MainWindow::switch_debug_mode() {
    if (debugWindow == nullptr) debugWindow = std::make_unique<DebugWindow>();
    if (debugWindow->isHidden()) {
        debugWindow->show();
    }
    else debugWindow->hide();
}

void MainWindow::cell_clicked(int row, int column) {
    if(debugWindow == nullptr) return;
    else {
        debugWindow->indicate_row(row);
        debugWindow->indicate_column(column);
        QTableWidgetItemAdapter adap(*ui->tableWidget);
        debugWindow->indicate_abs_index(adap.itemAt(row, column).abs_index());
    }
}
