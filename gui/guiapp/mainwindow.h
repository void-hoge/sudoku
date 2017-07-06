#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <array>
#include <memory>
#include <QMainWindow>
#include <QTableWidgetItem>
#include "board_facade.h"
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

        void refresh_table();

    private slots:
            void switch_debug_mode();
            void cell_clicked(int row, int column);
            void on_pushButton_released();
            void on_tableWidget_itemChanged(QTableWidgetItem *item);
};

#endif // MAINWINDOW_H
