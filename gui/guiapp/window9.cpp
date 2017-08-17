#include "window9.h"
#include "ui_window9.h"

window9::window9(QWidget *parent): QMainWindow(parent),
    ui(new Ui::window9),
    table_m{nullptr} {

    ui->setupUi(this);
    table_m = ui->tableWidget;
    if (table_m == nullptr) throw std::runtime_error("Couldn't get table component!");
    table_m->notice<V9_FLAG>();
}

window9::~window9() {
    delete ui;
}

void window9::on_actionTest_Input_triggered() {
    solver_m.test_input();
    table_m->set_data(solver_m.content());
}

void window9::on_pushButton_clicked() {
    solver_m.solve();
    table_m->set_data(solver_m.content());
}
