#include <FileManager.h>

FileManager::FileManager(fs::FS *fs)
{
        fileSystem = fs;
}
FileManager::~FileManager() {}

bool FileManager::begin()
{
        return fileSystem->begin();
}
void FileManager::end()
{
        fileSystem->end();
}
bool FileManager::format()
{
        return fileSystem->format();
}

FileStatus::Value FileManager::create(String directory, String fileName, String contents)
{
        File newFile;
        String absoluteFilePath = directory + fileName;
        if (fileSystem->exists(absoluteFilePath))
                return FileStatus::AlreadyExists;
        newFile = fileSystem->open(absoluteFilePath, "w");
        if (!newFile)
        {
                newFile.close();
                return FileStatus::CanNotOpen;
        }
        newFile.print(contents); // println will append \r and \n to the end of file and file length will be larger(2 unit)
        newFile.flush();
        delay(10);
        newFile.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::create(String directory, String fileName)
{
        File newFile;
        String absoluteFilePath = directory + fileName;
        if (fileSystem->exists(absoluteFilePath))
                return FileStatus::AlreadyExists;
        newFile = fileSystem->open(absoluteFilePath, "w");
        if (!newFile)
        {
                newFile.close();
                return FileStatus::CanNotOpen;
        }
        newFile.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::write(String directory, String fileName, String contents)
{
        File file;
        String absoluteFilePath = directory + fileName;

        if (!fileSystem->exists(absoluteFilePath))
                return FileStatus::DoesNotExist;
        file = fileSystem->open(absoluteFilePath, "w");
        if (!file)
                return FileStatus::CanNotOpen;
        file.write(contents.c_str());
        file.flush();
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::write(String directory, String fileName, uint8_t *contents, size_t fileSize)
{
        File file;
        String absoluteFilePath = directory + fileName;

        if (!fileSystem->exists(absoluteFilePath))
                return FileStatus::DoesNotExist;
        file = fileSystem->open(absoluteFilePath, "w");
        if (!file)
                return FileStatus::CanNotOpen;
        if (file.write(contents, fileSize) != fileSize)
                return FileStatus::Failed;
        file.flush();
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::append(String directory, String fileName, String contents)
{
        File file = fileSystem->open(directory + fileName, "a");
        if (!fileSystem->exists(directory + fileName))
                return FileStatus::DoesNotExist;
        if (!file)
                return FileStatus::CanNotOpen;
        file.print(contents);
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::append(String directory, String fileName, uint8_t *contents, size_t fileSize)
{
        File file = fileSystem->open(directory + fileName, "a");
        if (!fileSystem->exists(directory + fileName))
                return FileStatus::DoesNotExist;
        if (!file)
                return FileStatus::CanNotOpen;
        file.write(contents, fileSize);
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::read(String directory, String fileName, String &contents)
{
        File file;
        String absoluteFilePath = directory + fileName;
        if (!fileSystem->exists(absoluteFilePath))
                return FileStatus::DoesNotExist;
        file = fileSystem->open(absoluteFilePath, "r");
        if (!file)
        {
                file.close();
                return FileStatus::CanNotOpen;
        }
        while (file.available())
        {
                contents += (char)file.read();
                delay(1);
        }
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::deleteFile(String directory, String fileName)
{
        File file;
        String absoluteFilePath = directory + fileName;
        if (!fileSystem->exists(absoluteFilePath))
                return FileStatus::DoesNotExist;
        return fileSystem->remove(absoluteFilePath) ? FileStatus::Success : FileStatus::Failed;
}

FileStatus::Value FileManager::isPresent(String directory, String fileName)
{
        File file;
        String absoluteFilePath = directory + fileName;
        if (fileSystem->exists(absoluteFilePath))
                return FileStatus::AlreadyExists;
        return FileStatus::DoesNotExist;
}

File FileManager::getFile(String directory, String fileName)
{
        String absoluteFilePath = directory + fileName;
        return fileSystem->open(absoluteFilePath, "r+"); // Read and write mode
}

FileStatus::Value FileManager::clear(String directory, String fileName)
{
        return write(directory, fileName, "");
}