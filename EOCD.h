#ifndef KANKIRI_EOCD_H
#define KANKIRI_EOCD_H

#include <iostream>
#include <fstream>

using namespace std;

class EOCD {
private:
    ifstream& infile;
    const uint32_t EOCD_SIGNATURE = 0x06054b50;
    uint32_t diskNumber = 0;
    uint32_t centralDirectoryDisk = 0;
    uint32_t centralDirectoryRecordsOnThisDisk = 0;
    uint32_t totalCentralDirectoryRecords = 0;
    uint32_t centralDirectorySize = 0;
    uint32_t centralDirectoryOffset = 0;
    uint32_t commentLength = 0;
    string comment;
public:
    EOCD(ifstream&);

    uint32_t getDiskNumber() const;

    uint32_t getCentralDirectoryDisk() const;

    uint32_t getCentralDirectoryRecordsOnThisDisk() const;

    uint32_t getTotalCentralDirectoryRecords() const;

    uint32_t getCentralDirectorySize() const;

    uint32_t getCentralDirectoryOffset() const;

    uint32_t getCommentLength() const;

    const std::string &getComment() const;

    friend ostream &operator<<(ostream &os, const EOCD &eocd);
};


#endif //KANKIRI_EOCD_H
