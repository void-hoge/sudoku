#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <array>
#include <QMainWindow>
#include <QTableWidgetItem>

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
    std::array<QTableWidgetItem*, tableSize*tableSize> itemPtrs;
};

#endif // MAINWINDOW_H
