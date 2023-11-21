// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onFileListReady(vector<CentralFileHeader> &fileList) {
    ui->treeWidget->setColumnCount(3);
    ui->treeWidget->setColumnWidth(0, 300);
    ui->treeWidget->setColumnWidth(1, 200);
    ui->treeWidget->setColumnWidth(2, 100);
    ui->treeWidget->setHeaderItem(new QTreeWidgetItem(QStringList({"Name", "Last modified", "Size"})));
    for (const auto &i: fileList) {
        ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(
                {QString::fromStdString(i.getFilename()),
                 i.getLastModifiedDateTime().toString("yyyy-MM-dd hh:mm:ss"),
                 QString("%1").arg(i.getUncompressedSize())
                }
        )));
    }
//    ui->treeWidget->resizeColumnToContents(0);
    auto numberOfFiles = fileList.size();
    ui->label->setText(QString("%1 file%2").arg(numberOfFiles).arg(numberOfFiles == 1 ? "" : "s"));
}
