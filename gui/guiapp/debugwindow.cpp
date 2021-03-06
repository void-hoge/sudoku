#include <cctype>
#include <cassert>
#include "debugwindow.h"
#include "ui_debugwindow.h"
#include "table_fragment.h"

DebugWindow::DebugWindow(QWidget *parent): QMainWindow(parent), size{0},
    ui(new Ui::DebugWindow),
    row_textview_m { nullptr },
    column_textview_m { nullptr },
    abs_index_textview_m { nullptr },
    contents_view_m { nullptr } {

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
    row_textview_m->setText("Row : " + QString::number(r));
}

void DebugWindow::indicate_column(int c) {
    column_textview_m->setText("Column : " + QString::number(c));
}

void DebugWindow::indicate_abs_index(int i) {
    abs_index_textview_m->setText("(low abs index : " + QString::number(i) + ")");
}

void DebugWindow::indicate_content_number(int c) {
    contents_view_m->setText(QString("Content : ") + QString::number(c));
}

void DebugWindow::indicate_content_NaN() {
    contents_view_m->setText("NaN");
}

void DebugWindow::focus_on(const QTableWidgetItem &i) {
    indicate_row(i.row());
    indicate_column(i.column());
    if (size == V16_FLAG::size)
        indicate_abs_index(point<V16_FLAG>{i.row(), i.column()}.abs_pos());
    else if (size == V9_FLAG::size)
        indicate_abs_index(point<V9_FLAG>{i.row(), i.column()}.abs_pos());
    else assert(false);
    {
        auto content = i.text().toStdString();
        // if content consists of numbers
        if (std::all_of(content.begin(), content.end(), isdigit)) indicate_content_number(std::stoi(content));
        else {
            if (content == " ") indicate_content_number(0);    // only if that is a space char, not an error.
            else indicate_content_NaN();
        }
    }
}
