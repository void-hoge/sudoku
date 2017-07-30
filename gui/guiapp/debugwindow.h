#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLabel>

namespace Ui {
class DebugWindow;
}

class DebugWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit DebugWindow(QWidget *parent = 0);
    ~DebugWindow();

    void indicate_row(int r);
    void indicate_column(int c);
    void indicate_abs_index(int i);
    void indicate_content_number(int c);
    void focus_on(const QTableWidgetItem& i);

private:
    Ui::DebugWindow *ui;
    QLabel* row_textview_m;
    QLabel* column_textview_m;
    QLabel* abs_index_textview_m;
    QLabel* contents_view_m;
};

#endif // DEBUGWINDOW_H
