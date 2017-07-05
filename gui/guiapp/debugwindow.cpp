#include "debugwindow.h"
#include "ui_debugwindow.h"

DebugWindow::DebugWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::DebugWindow) {
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}

DebugWindow::~DebugWindow() {
    delete ui;
}
