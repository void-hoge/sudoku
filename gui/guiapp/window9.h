#ifndef WINDOW9_H
#define WINDOW9_H

#include <QMainWindow>
#include "table_fragment.h"

#include "solver.h"

namespace Ui {
class window9;
}

class window9 : public QMainWindow {
    Q_OBJECT
public:
    explicit window9(QWidget *parent = 0);
    ~window9();

private slots:
    void on_actionTest_Input_triggered();

    void on_pushButton_clicked();

private:
    Ui::window9 *ui;
    table_fragment* table_m;

    solver<V9_FLAG> solver_m;
};

#endif // WINDOW9_H
