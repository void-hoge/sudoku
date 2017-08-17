#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QMainWindow>
#include "window16.h"
#include "window9.h"

namespace Ui {
    class launcher;
}

class launcher : public QMainWindow {
       Q_OBJECT
    public:
        explicit launcher(QWidget *parent = 0);
        ~launcher();

    private slots:
        void on_Start9x9_clicked();
        void on_Start16x16_clicked();

    private:
        Ui::launcher *ui;
        window16* w16;
        window9* w9;
};

#endif // LAUNCHER_H
