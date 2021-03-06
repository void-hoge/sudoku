#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include "solver.h"
#include "mainwindow.h"
#include "utils.h"
#include "solver_facade.h"
#include "table_fragment.h"
#include "debugwindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui = nullptr;
        table_fragment* table_m = nullptr;
        std::unique_ptr<DebugWindow> debugWindow;

        //solver_facade solver_m;
        solver<V16_FLAG> solver_m;

        void closeEvent(QCloseEvent* event) override;
    private slots:
            void switch_debug_mode();
            void cell_clicked(int row, int column);
            void on_pushButton_released();
            void on_actionTest_Input_2_triggered();
};

#endif // MAINWINDOW_H
