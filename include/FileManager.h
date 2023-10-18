/**
 * @author Hossein vahabi
 * @version 1.0
 * @see https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html
 */
#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#endif

#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef FILE_STATUS_H
#include <FileStatus.h>
#endif

#ifndef FS_H
#include <FS.h>
#endif

#ifdef LITTLE_FS
#ifndef __LITTLEFS_H
#include <LittleFS.h>
#endif
#endif

class FileManager
{
private:
        fs::FS *fileSystem = nullptr;

public:
        FileManager(fs::FS *fs);
        ~FileManager();
        bool begin();
        void end();
        bool format();
        /* Create */
        FileStatus::Value create(String directory, String fileName, String contents);
        FileStatus::Value create(String directory, String fileName);
        /* Update */
        FileStatus::Value write(String directory, String fileName, String contents);
        FileStatus::Value write(String directory, String fileName, uint8_t *contents, size_t fileSize);
        FileStatus::Value append(String directory, String fileName, String contents);
        FileStatus::Value append(String directory, String fileName, uint8_t *contents, size_t fileSize);
        FileStatus::Value clear(String directory, String fileName);
        /* Read */
        FileStatus::Value read(String directory, String fileName, String &contents);
        /* Delete */
        FileStatus::Value deleteFile(String directory, String fileName);
        /* Other Methods */
        FileStatus::Value isPresent(String directory, String fileName);
        File getFile(String directory, String fileName);
};