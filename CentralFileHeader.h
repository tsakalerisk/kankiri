#ifndef KANKIRI_CENTRALFILEHEADER_H
#define KANKIRI_CENTRALFILEHEADER_H

#include <fstream>
#include <ostream>

using namespace std;

class CentralFileHeader {
private:
    ifstream& infile;
    const uint32_t CENTRAL_DIRECTORY_SIGNATURE = 0x02014b50;
    uint32_t version = 0;
    uint32_t minimumVersion = 0;
    uint32_t generalPurposeBitFlag = 0;
    uint32_t compressionMethod = 0;
    uint32_t lastModifiedTime = 0;
    uint32_t lastModifiedDate = 0;
    uint32_t uncompressedData = 0;
    uint32_t compressedSize = 0;
    uint32_t uncompressedSize = 0;
    uint32_t filenameLength = 0;
    uint32_t extraFieldLength = 0;
    uint32_t fileCommentLength = 0;
    uint32_t fileStartDisk = 0;
    uint32_t internalFileAttributes = 0;
    uint32_t externalFileAttributes = 0;
    uint32_t localHeaderOffset = 0; //relative to disk start
    string filename;
    string extraField;
    string fileComment;

public:
    CentralFileHeader(ifstream&);

    uint32_t getVersion() const;

    uint32_t getMinimumVersion() const;

    uint32_t getGeneralPurposeBitFlag() const;

    uint32_t getCompressionMethod() const;

    uint32_t getLastModifiedTime() const;

    uint32_t getLastModifiedDate() const;

    uint32_t getUncompressedData() const;

    uint32_t getCompressedSize() const;

    uint32_t getUncompressedSize() const;

    uint32_t getFilenameLength() const;

    uint32_t getExtraFieldLength() const;

    uint32_t getFileCommentLength() const;

    uint32_t getFileStartDisk() const;

    uint32_t getInternalFileAttributes() const;

    uint32_t getExternalFileAttributes() const;

    uint32_t getLocalHeaderOffset() const;

    const string &getFilename() const;

    const string &getExtraField() const;

    const string &getFileComment() const;

    friend ostream &operator<<(ostream &os, const CentralFileHeader &header);
};


#endif //KANKIRI_CENTRALFILEHEADER_H
