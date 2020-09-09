#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QAction* areaAction;
    QAction* preAction;
    QAction* subAction;

    QMenu* actionsMenu;

    QToolBar* toolBar;

    QLabel* statusLabel;

public slots:
    void InsertArea();
    void InsertPrefix();
    void InsertSub();
    void Dial();
};

#endif // MAINWINDOW_H
