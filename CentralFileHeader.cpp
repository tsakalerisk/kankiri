#include "CentralFileHeader.h"

#include <cstring>

CentralFileHeader::CentralFileHeader(ifstream &infile) : infile(infile) {
    char buffer[4];
    infile.read(buffer, 4);
    if (memcmp(buffer, &CENTRAL_DIRECTORY_SIGNATURE, 4) != 0)
        throw runtime_error("Invalid signature");
    infile.read(reinterpret_cast<char *>(&version), 2);
    infile.read(reinterpret_cast<char *>(&minimumVersion), 2);
    infile.read(reinterpret_cast<char *>(&generalPurposeBitFlag), 2);
    infile.read(reinterpret_cast<char *>(&compressionMethod), 2);
    infile.read(reinterpret_cast<char *>(&lastModifiedTime), 2);
    infile.read(reinterpret_cast<char *>(&lastModifiedDate), 2);
    infile.read(reinterpret_cast<char *>(&uncompressedData), 4);
    infile.read(reinterpret_cast<char *>(&compressedSize), 4);
    infile.read(reinterpret_cast<char *>(&uncompressedSize), 4);
    infile.read(reinterpret_cast<char *>(&filenameLength), 2);
    infile.read(reinterpret_cast<char *>(&extraFieldLength), 2);
    infile.read(reinterpret_cast<char *>(&fileCommentLength), 2);
    infile.read(reinterpret_cast<char *>(&fileStartDisk), 2);
    infile.read(reinterpret_cast<char *>(&internalFileAttributes), 2);
    infile.read(reinterpret_cast<char *>(&externalFileAttributes), 4);
    infile.read(reinterpret_cast<char *>(&localHeaderOffset), 4);
    filename.resize(filenameLength);
    infile.read(&filename[0], filenameLength);
    extraField.resize(extraFieldLength);
    infile.read(&extraField[0], extraFieldLength);
    fileComment.resize(fileCommentLength);
    infile.read(&fileComment[0], fileCommentLength);
}

uint32_t CentralFileHeader::getVersion() const {
    return version;
}

uint32_t CentralFileHeader::getMinimumVersion() const {
    return minimumVersion;
}

uint32_t CentralFileHeader::getGeneralPurposeBitFlag() const {
    return generalPurposeBitFlag;
}

uint32_t CentralFileHeader::getCompressionMethod() const {
    return compressionMethod;
}

uint32_t CentralFileHeader::getLastModifiedTime() const {
    return lastModifiedTime;
}

uint32_t CentralFileHeader::getLastModifiedDate() const {
    return lastModifiedDate;
}

uint32_t CentralFileHeader::getUncompressedData() const {
    return uncompressedData;
}

uint32_t CentralFileHeader::getCompressedSize() const {
    return compressedSize;
}

uint32_t CentralFileHeader::getUncompressedSize() const {
    return uncompressedSize;
}

uint32_t CentralFileHeader::getFilenameLength() const {
    return filenameLength;
}

uint32_t CentralFileHeader::getExtraFieldLength() const {
    return extraFieldLength;
}

uint32_t CentralFileHeader::getFileCommentLength() const {
    return fileCommentLength;
}

uint32_t CentralFileHeader::getFileStartDisk() const {
    return fileStartDisk;
}

uint32_t CentralFileHeader::getInternalFileAttributes() const {
    return internalFileAttributes;
}

uint32_t CentralFileHeader::getExternalFileAttributes() const {
    return externalFileAttributes;
}

uint32_t CentralFileHeader::getLocalHeaderOffset() const {
    return localHeaderOffset;
}

const string &CentralFileHeader::getFilename() const {
    return filename;
}

const string &CentralFileHeader::getExtraField() const {
    return extraField;
}

const string &CentralFileHeader::getFileComment() const {
    return fileComment;
}

ostream &operator<<(ostream &os, const CentralFileHeader &header) {
    os << "Filename: " << header.filename << endl
       << "Version: " << header.version << endl
       << "Minimum version: " << header.minimumVersion << endl
       << "General purpose bit flag: " << header.generalPurposeBitFlag << endl
       << "Compression method: " << header.compressionMethod << endl
       << "Last modified time: " << header.lastModifiedTime << endl
       << "Last modified date: " << header.lastModifiedDate << endl
       << "Uncompressed data: " << header.uncompressedData << endl
       << "Compressed size: " << header.compressedSize << endl
       << "Uncompressed size: " << header.uncompressedSize << endl
       << "Filename length: " << header.filenameLength << endl
       << "Extra field length: " << header.extraFieldLength << endl
       << "File comment length: " << header.fileCommentLength << endl
       << "File start disk: " << header.fileStartDisk << endl
       << "Internal file attributes: " << header.internalFileAttributes << endl
       << "External file attributes: " << header.externalFileAttributes << endl
       << "Local header offset: " << header.localHeaderOffset << endl
       << "Extra field: " << header.extraField << endl
       << "File comment: " << header.fileComment;
    return os;
}
