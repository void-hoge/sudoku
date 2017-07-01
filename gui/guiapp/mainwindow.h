#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <array>
#include <QMainWindow>
#include <QTableWidgetItem>
#include "board_facade.h"

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
    protected slots:
        void activate_debug_mode();
};

#endif // MAINWINDOW_H
