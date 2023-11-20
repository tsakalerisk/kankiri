//
// Created by User on 20/11/2023.
//

#include "EOCD.h"

#include <cstring>

EOCD::EOCD(ifstream &infile) : infile(infile) {
    //find signature
    infile.seekg(-4, ios_base::end);
    char buffer[4];
    infile.read(buffer, 4);
    while (memcmp(buffer, &EOCD_SIGNATURE, 4) != 0) {
        infile.seekg(-5, ios_base::cur);
        infile.read(buffer, 4);
        if (infile.fail()) break;
    }

    if (infile.fail()) throw runtime_error("Invalid file");

    infile.read(reinterpret_cast<char *>(&diskNumber), 2);
    infile.read(reinterpret_cast<char *>(&centralDirectoryDisk), 2);
    infile.read(reinterpret_cast<char *>(&centralDirectoryRecordsOnThisDisk), 2);
    infile.read(reinterpret_cast<char *>(&totalCentralDirectoryRecords), 2);
    infile.read(reinterpret_cast<char *>(&centralDirectorySize), 4);
    infile.read(reinterpret_cast<char *>(&centralDirectoryOffset), 4);
    infile.read(reinterpret_cast<char *>(&commentLength), 2);
    comment.resize(commentLength);
    infile.read(&comment[0], commentLength);
}

uint32_t EOCD::getDiskNumber() const {
    return diskNumber;
}

uint32_t EOCD::getCentralDirectoryDisk() const {
    return centralDirectoryDisk;
}

uint32_t EOCD::getCentralDirectoryRecordsOnThisDisk() const {
    return centralDirectoryRecordsOnThisDisk;
}

uint32_t EOCD::getTotalCentralDirectoryRecords() const {
    return totalCentralDirectoryRecords;
}

uint32_t EOCD::getCentralDirectorySize() const {
    return centralDirectorySize;
}

uint32_t EOCD::getCentralDirectoryOffset() const {
    return centralDirectoryOffset;
}

uint32_t EOCD::getCommentLength() const {
    return commentLength;
}

const std::string &EOCD::getComment() const {
    return comment;
}

ostream &operator<<(ostream &os, const EOCD &eocd) {
    os << "Disk number: " << eocd.diskNumber << endl
       << "Central directory disk: " << eocd.centralDirectoryDisk << endl
       << "Central directory records on this disk: " << eocd.centralDirectoryRecordsOnThisDisk << endl
       << "Total central directory records: " << eocd.totalCentralDirectoryRecords << endl
       << "Central directory size: " << eocd.centralDirectorySize << endl
       << "Central directory offset: " << eocd.centralDirectoryOffset << endl
       << "Comment length: " << eocd.commentLength << endl
       << "Comment: " << eocd.comment;
    return os;
}
