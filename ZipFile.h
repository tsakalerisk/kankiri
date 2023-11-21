//
// Created by User on 20/11/2023.
//

#ifndef KANKIRI_ZIPFILE_H
#define KANKIRI_ZIPFILE_H

#include <QObject>
#include <fstream>
#include "CentralFileHeader.h"

class ZipFile : public QObject {

Q_OBJECT

public:
    ~ZipFile();

    void openFile(string filename);

    bool isOpen();

signals:
    void fileListReady(vector<CentralFileHeader>& fileList);

private:
    ifstream infile;
};


#endif //KANKIRI_ZIPFILE_H
