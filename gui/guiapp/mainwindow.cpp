#include <memory>
#include <QString>
#include <QTableWidget>
#include <QHeaderView>
#include <QtCore/QThread>
#include <QProgressDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "debugwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), solver_m {} {
    ui->setupUi(this);

    // init member
    table_m = ui->tableWidget;
    // check
    if (table_m == nullptr) throw std::runtime_error("Couldn't get ui components on MainWindow.");

    // init widgets
    table_m->set_data(solver_m.current_state());

    // connect
    connect(ui->actionSwitch_debug_mode, SIGNAL(triggered()), this, SLOT(switch_debug_mode()));
    connect(table_m, SIGNAL(cellClicked(int,int)), this, SLOT(cell_clicked(int, int)));
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
    if (debugWindow->isHidden()) debugWindow->show();
    else debugWindow->hide();
}

void MainWindow::cell_clicked(int row, int column) {
    if(debugWindow == nullptr) return;
    else if (table_m == nullptr) throw std::runtime_error("table is uninitialized!");
    else debugWindow->focus_on(table_m->ref_to_item(row, column));
}

void MainWindow::on_pushButton_released() {
    solver_m.solve(table_m->packaged_data());
    table_m->set_data(solver_m.current_state());
}

// Test input
void MainWindow::on_actionTest_Input_2_triggered() {
    solver_m.low_solver().testInput();
    table_m->set_data(solver_m.current_state());
}
