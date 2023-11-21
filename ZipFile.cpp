#include "ZipFile.h"

#include <iostream>
#include <vector>
#include "EOCD.h"
#include "CentralFileHeader.h"

using namespace std;

ZipFile::~ZipFile() {
    infile.close();
}

void ZipFile::openFile(std::string filename) {
    infile.open(filename, ios::binary);
    EOCD eocd(infile);
    infile.seekg(eocd.getCentralDirectoryOffset(), ios_base::beg);
    vector<CentralFileHeader> fileList;
    while (infile.tellg() < eocd.getCentralDirectoryOffset() + eocd.getCentralDirectorySize()) {
        fileList.push_back(CentralFileHeader(infile));
    }
    emit fileListReady(fileList);
}

bool ZipFile::isOpen() {
    return infile.is_open();
}
