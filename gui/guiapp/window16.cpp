#include <stdexcept>
#include "window16.h"
#include "ui_window16.h"

window16::window16(QWidget *parent): QMainWindow{parent},
    ui{new Ui::window16},
    table_m{nullptr} {

    ui->setupUi(this);

    // setup table
    table_m = ui->tableWidget;
    if (table_m == nullptr) throw std::runtime_error("Couldn't get table component!");
    table_m->notice<V16_FLAG>();
}

window16::~window16() {
    delete ui;
}

void window16::on_actionTest_Input_triggered() {
    solver_m.test_input();
    table_m->set_data(solver_m.content());
}

void window16::on_pushButton_clicked() {
    solver_m.solve();
    table_m->set_data(solver_m.content());
}
