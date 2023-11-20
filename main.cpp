#include <iostream>
#include <QApplication>
#include <QPushButton>

#include "ZipFile.h"

using namespace std;

int main(int argc, char *argv[]) {
    ZipFile zipFile(argv[1]);
    cout << (zipFile.isOpen() ? "File opened" : "File not found") << endl;
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
