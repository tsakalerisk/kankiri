//
// Created by User on 20/11/2023.
//

#ifndef KANKIRI_ZIPFILE_H
#define KANKIRI_ZIPFILE_H

#include <fstream>

class ZipFile {
private:
    std::ifstream infile;
public:
    ZipFile(char *);
    ~ZipFile();
    bool isOpen();
};


#endif //KANKIRI_ZIPFILE_H
