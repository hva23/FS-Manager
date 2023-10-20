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

### Better use LittleFS instead of SPIFFS
This library is specifically designed and tested for use with LittleFS. Due to the deprecation of SPIFFS and its potential removal in future releases, we strongly recommend using LittleFS as the underlying file system with this library.
Using SPIFFS instead may result in compatibility issues and bugs. Therefore, it is highly advised to utilize LittleFS to ensure optimal performance and stability.

## Installation

### Arduino
1. Download the .zip file from github tag section.
2. In the Arduino IDE, open the **"Sketch"** menu.
3. Click on **"Include Library"**.
4. Select **"Add .ZIP Library..."** from the drop-down menu that appears.
### PlatformIO
Add https://github.com/hva23/FS-Manager.git to ```lib_deps``` tag in ```platformio.ini``` file.<br>
Or add ```hva23/FS-Manager@^(desired_version)``` to to ```lib_deps``` tag in ```platformio.ini``` file.<br>

## Usage
### Basic operations
#### Define file system kind in constructor
```c++
FileManager fileManager(&LittleFS);
// or FileManager fileManager(&SPIFFS);
```
#### Starting the file system
```c++
bool begin();
```
#### CRUD Operations
#### Create:
```directory``` -Where file will be created<br>
```fileName``` -File name<br>
```contents``` -Init content to write to file, could be null<br>
```c++
/* Create */
FileStatus::Value create(String directory, String fileName, String contents);
```

#### Read:
```directory``` -Where file will be read<br>
```fileName``` -File name<br>
```contents``` -The contents of the file will be stored in it<br>
```c++
/* Read */
FileStatus::Value read(String directory, String fileName, String &contents);
```

#### Update:
```directory``` -Where file will be updated<br>
```fileName``` -File name<br>
```contents``` -The contents to replace<br>
```
/* Update */
FileStatus::Value write(String directory, String fileName, String contents);
```

<br>```directory``` -Where file will be updated<br>
```fileName``` -File name<br>
```contents``` -An array of ```uint8_t``` data type to write and replace the previous contents<br>
```fileSize``` -Size of ```uint8_t``` array<br>
```c++
/* Update */
FileStatus::Value write(String directory, String fileName, uint8_t *contents, size_t fileSize);
```

<br>```directory``` -Where file will be updated<br>
```fileName``` -File name<br>
```contents``` -The contents to add to the previous contents<br>
```c++
/* Update */
FileStatus::Value append(String directory, String fileName, String contents);
```

<br>```directory``` -Where file will be updated<br>
```fileName``` -File name<br>
```contents``` -An array of ```uint8_t``` data type to write and add to the previous contents<br>
```fileSize``` -Size of ```uint8_t``` array<br>
```c++
/* Update */
FileStatus::Value append(String directory, String fileName, uint8_t *contents, size_t fileSize);
```

#### Delete:
```directory``` -Where file will be deleted<br>
```fileName``` -File name<br>
```c++
/* Delete */
FileStatus::Value deleteFile(String directory, String fileName);
```

## Examples
**CRUD Example**
```c++
const String dir = "Directory1/Subdirectory1/";
const String fileName = "file.txt";

FileManager fileManager(&LittleFS);
FileStatus::Value fileStatus;

/* LittleFS or SPIFFS */
fileManager.begin();

fileStatus = fileManager.create(dir, fileName);
if (fileStatus != FileStatus::Success)
        Serial.println("File creation failed");
else
{
  String contentsToWrite = "Hello world!";
  fileStatus = fileManager.write(dir, fileName, contentsToWrite);
  if(fileStatus == FileStatus::Failed)
          Serial.println("File write failed");
  else
  {
    String fileContents = "";
    fileStatus = fileManager.read(dir, fileName, fileContents);
    if(fileStatus == FileStatus::Success)
    {
      Serial.println("File reading was successful!");
      Serial.print("Contents : ");
      Serial.println(fileContents);
    }
  }
}
```
