#include "launcher.h"
#include "ui_launcher.h"

launcher::launcher(QWidget *parent): QMainWindow(parent),
    ui(new Ui::launcher) {

    ui->setupUi(this);
}

launcher::~launcher() {
    delete ui;
}

void launcher::on_Start9x9_clicked() {
    w9 = new window9{};
    w9->show();
}

void launcher::on_Start16x16_clicked() {
    w16 = new window16{};
    w16->show();
}
