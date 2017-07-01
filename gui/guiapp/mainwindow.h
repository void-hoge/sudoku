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
    static constexpr int tableSize = 16;
    BoardFacade board;
    QTableWidget* table;
};

#endif // MAINWINDOW_H
