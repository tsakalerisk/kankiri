#ifndef KANKIRI_MAINWINDOW_H
#define KANKIRI_MAINWINDOW_H

#include <QMainWindow>
#include "CentralFileHeader.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:
    void onFileListReady(vector<CentralFileHeader>& fileList);

private:
    Ui::MainWindow *ui;
};


#endif //KANKIRI_MAINWINDOW_H
