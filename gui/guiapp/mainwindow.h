#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <array>
#include <memory>
#include <QMainWindow>
#include <QTableWidgetItem>
#include "board_facade.h"
#include "../../16x16/Solver/Solver.h"
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
        Ui::MainWindow *ui;
        BoardFacade board;

        QTableWidget* table;
        std::unique_ptr<DebugWindow> debugWindow;

        void closeEvent(QCloseEvent* event) override;
    private slots:
            void switch_debug_mode();
            void cell_clicked(int row, int column);
            void on_pushButton_released();
};

#endif // MAINWINDOW_H
