# FS-Manager

The FS-Manager is a high-level library that provides an easy way to manage files and directories.

## Table of Contents

- [About the Project](#about-the-project)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## About the Project

The FS-Manager is a high-level file system interface designed specifically for Arduino-based projects. It provides an easy-to-use and efficient way to manage files and directories on devices that support LittleFS or SPIFFS (Serial Peripheral Interface Flash File System).

With this library, you can perform various file operations such as creating, opening, reading, writing, and deleting files. It abstracts the low-level complexities of interacting with the underlying file system, allowing you to focus on implementing your project's logic without worrying about the intricacies of file management.

## Installation

### Arduino
1. Download the .zip file from tag section.
2. In the Arduino IDE, open the **"Sketch"** menu.
3. Click on **"Include Library"**.
4. Select **"Add .ZIP Library..."** from the drop-down menu that appears.
### PlatformIO
Add https://github.com/hva23/FS-Manager.git to **lib_deps** tag in **"platformio.ini"** file.<br>
Also it will be available in PlatformIO libraries as soon as possible to install it easily

## Usage
### Basic operations
#### Starting the file system
```c++
bool begin(fs::FS &fs);
```
#### CRUD Operations
#### Create:
```fs``` -File System Type<br>
```directory``` -Where file will be created<br>
```fileName``` -File name<br>
```contents``` -Init content to write to file, could be null<br>
```c++
/* Create */
FileStatus::Value create(fs::FS &fs, String directory, String fileName, String contents);
```

#### Read:
```fs``` -File System Type<br>
```directory``` -Where file will be read<br>
```fileName``` -File name<br>
```contents``` -The contents of the file will be stored in it<br>
```c++
/* Read */
FileStatus::Value read(fs::FS &fs, String directory, String fileName, String &contents);
```

#### Update:
```fs``` -File System Type<br>
```directory``` -Where file will be updated<br>
```fileName``` -File name<br>
```contents``` -The contents to replace<br>
```
/* Update */
FileStatus::Value write(fs::FS &fs, String directory, String fileName, String contents);
```

<br>```fs``` -File System Type<br>
```directory``` -Where file will be updated<br>
```fileName``` -File name<br>
```contents``` -An array of ```uint8_t``` data type to write and replace the previous contents<br>
```fileSize``` -Size of ```uint8_t``` array<br>
```c++
/* Update */
FileStatus::Value write(fs::FS &fs, String directory, String fileName, uint8_t *contents, size_t fileSize);
```

<br>```fs``` -File System Type<br>
```directory``` -Where file will be updated<br>
```fileName``` -File name<br>
```contents``` -The contents to add to the previous contents<br>
```c++
/* Update */
FileStatus::Value append(fs::FS &fs, String directory, String fileName, String contents);
```

<br>```fs``` -File System Type<br>
```directory``` -Where file will be updated<br>
```fileName``` -File name<br>
```contents``` -An array of ```uint8_t``` data type to write and add to the previous contents<br>
```fileSize``` -Size of ```uint8_t``` array<br>
```c++
/* Update */
FileStatus::Value append(fs::FS &fs, String directory, String fileName, uint8_t *contents, size_t fileSize);
```

#### Delete:
```fs``` -File System Type<br>
```directory``` -Where file will be deleted<br>
```fileName``` -File name<br>
```c++
/* Delete */
FileStatus::Value deleteFile(fs::FS &fs, String directory, String fileName);
```

## Examples
**CRUD Example**
```c++
const String dir = "Directory1/Subdirectory1/";
const String fileName = "file.txt";

FileManager fileManager;
FileStatus::Value fileStatus;

/* LittleFS or SPIFFS */
fileManager.begin(LittleFS);

fileStatus = fileManager.create(LittleFS, dir, fileName);
if (fileStatus != FileStatus::Success)
        Serial.println("File creation failed");
else
{
  String contentsToWrite = "Hello world!";
  fileStatus = fileManager.write(LittleFS, dir, fileName, contentsToWrite);
  if(fileStatus == FileStatus::Failed)
          Serial.println("File write failed");
  else
  {
    String fileContents = "";
    fileStatus = fileManager.read(LittleFS, dir, fileName, fileContents);
    if(fileStatus == FileStatus::Success)
    {
      Serial.println("File reading was successful!");
      Serial.print("Contents : ");
      Serial.println(fileContents);
    }
  }
}
```
