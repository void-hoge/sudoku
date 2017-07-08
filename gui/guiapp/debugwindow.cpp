#include "debugwindow.h"
#include "ui_debugwindow.h"
#include "table_fragment.h"

DebugWindow::DebugWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::DebugWindow) {
    ui->setupUi(this);
    // init member
    row_textview_m = ui->row_text;
    column_textview_m = ui->column_text;
    abs_index_textview_m = ui->abs_index;
    contents_view_m = ui->contents_view;
    // check
    if (row_textview_m == nullptr ||
            column_textview_m == nullptr ||
            abs_index_textview_m == nullptr ||
            contents_view_m == nullptr) {
        throw std::runtime_error("Could'nt get pointers to widgets on debugwindow.");
    }

    // init window and layout
    setWindowTitle("Debug Window");
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    ui->idinfo_layout->setAlignment(Qt::AlignLeft);
    
    // init widgets
    row_textview_m->setText("N/A");
    column_textview_m->setText("N/A");
    abs_index_textview_m->setText("N/A");
    contents_view_m->setText("N/A");
}

DebugWindow::~DebugWindow() {
    delete ui;
}

void DebugWindow::indicate_row(int r) {
    if (row_textview_m == nullptr) throw std::runtime_error("Pointer to row indicator is null!");
    else row_textview_m->setText("Row : " + QString::number(r));
}

void DebugWindow::indicate_column(int c) {
    if (column_textview_m == nullptr) throw std::runtime_error("Pointer to column indicator is null!");
    else column_textview_m->setText("Column : " + QString::number(c));
}

void DebugWindow::indicate_abs_index(int i) {
    if (abs_index_textview_m == nullptr) throw std::runtime_error("Pointer to low abs index indicator is null!");
    else abs_index_textview_m->setText("(low abs index : " + QString::number(i) + ")");
}

void DebugWindow::focus_on(const QTableWidgetItem &i) {
    indicate_row(i.row());
    indicate_column(i.column());
    indicate_abs_index(table_fragment::cast_to_abs(i.row(), i.column()));
}
