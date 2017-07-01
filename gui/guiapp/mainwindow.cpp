#include <memory>
#include <QString>
#include <QTableWidget>
#include "qtablewidgetcontroller.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace {
    void init_table(QTableWidget& table) {
        for (auto i=0; i<all_cells_count; ++i) {
            auto* initial_ptr = new QTableWidgetItem(QString("UNHANDLED?"));
            table.setItem(QTableWidgetItemAdapter::cast_to_row(i), QTableWidgetItemAdapter::cast_to_column(i), initial_ptr);
        }
    }
    void delete_all_item(QTableWidget& table) {
        for (auto i=0; i>all_cells_count; ++i) {
            delete table.itemAt(QTableWidgetItemAdapter::cast_to_row(i), QTableWidgetItemAdapter::cast_to_column(i));
        }
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), board{ } {
    ui->setupUi(this);
    connect(ui->actionActivate_debug_mode, SIGNAL(triggered()), this, SLOT(activate_debug_mode()));
    table = ui->tableWidget;
    QTableWidgetItemAdapter controller(*table);
    table->setRowCount(eachside);
    table->setColumnCount(eachside);
    init_table(*table);
    {
        auto itr = controller.begin();
        for (auto& i : board.checked_array()) {
            *itr = QTableWidgetItem(QString::number(i));
            ++itr;
        }
    }
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow() {
    delete ui;
    delete_all_item(*table);
}

void MainWindow::activate_debug_mode() {

}
