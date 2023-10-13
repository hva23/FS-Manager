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
        FileStatus::Value create(fs::FS &fs, String directory, String fileName, String contents);
        FileStatus::Value create(fs::FS &fs, String directory, String fileName);
        FileStatus::Value write(fs::FS &fs, String directory, String fileName, String contents);
        FileStatus::Value write(fs::FS &fs, String directory, String fileName, uint8_t *contents, size_t fileSize);
        FileStatus::Value append(fs::FS &fs, String directory, String fileName, String contents);
        FileStatus::Value append(fs::FS &fs, String directory, String fileName, uint8_t *contents, size_t fileSize);
        FileStatus::Value read(fs::FS &fs, String directory, String fileName, String &contents);
        FileStatus::Value deleteFile(fs::FS &fs, String directory, String fileName);
        FileStatus::Value isPresent(fs::FS &fs, String directory, String fileName);
        File getFile(fs::FS &fs, String directory, String fileName);
        FileStatus::Value clear(fs::FS &fs, String directory, String fileName);
};