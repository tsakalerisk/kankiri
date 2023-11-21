#include <iostream>
#include <QApplication>

#include "ZipFile.h"
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    ZipFile zipFile;
    QApplication a(argc, argv);
    QApplication::setStyle("fusion");

    auto *mainWindow = new MainWindow();
    QObject::connect(&zipFile, &ZipFile::fileListReady, mainWindow, &MainWindow::onFileListReady);

    try {
        zipFile.openFile(string(argv[1]));
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    mainWindow->show();
    return QApplication::exec();
}
