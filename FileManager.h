/**
 * @author Hossein vahabi
 * @version 1.0
 * @see https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html
 */

#include <FS.h>
#include <LittleFS.h>
#include <Arduino.h>
#include <FileStatus.h>

class FileManager
{
private:
public:
        FileManager();
        ~FileManager();
        bool begin(fs::FS &fs);
        FileStatus create(fs::FS &fs, String directory, String fileName, String contents);
        FileStatus create(fs::FS &fs, String directory, String fileName);
        FileStatus write(fs::FS &fs, String directory, String fileName, String contents);
        FileStatus write(fs::FS &fs, String directory, String fileName, uint8_t *contents, size_t fileSize);
        FileStatus append(fs::FS &fs, String directory, String fileName, String contents);
        FileStatus append(fs::FS &fs, String directory, String fileName, uint8_t *contents, size_t fileSize);
        FileStatus read(fs::FS &fs, String directory, String fileName, String &contents);
        FileStatus deleteFile(fs::FS &fs, String directory, String fileName);
        FileStatus isPresent(fs::FS &fs, String directory, String fileName);
        File getFile(fs::FS &fs, String directory, String fileName);
        FileStatus clear(fs::FS &fs, String directory, String fileName);
};