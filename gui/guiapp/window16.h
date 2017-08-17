#ifndef WINDOW16_H
#define WINDOW16_H

#include <QMainWindow>
#include "table_fragment.h"

#include "solver.h"

namespace Ui {
    class window16;
}

class window16 : public QMainWindow {
        Q_OBJECT
    public:
        explicit window16(QWidget *parent = 0);
        ~window16();

private slots:
    void on_actionTest_Input_triggered();
    void on_pushButton_clicked();

private:
        Ui::window16 *ui;
        table_fragment* table_m;

        solver<V16_FLAG> solver_m;
};

#endif // WINDOW16_H
