#include <FileManager.h>

FileManager::FileManager() {}
FileManager::~FileManager() {}

bool FileManager::begin(fs::FS &fs)
{
        return fs.begin();
}

FileStatus::Value FileManager::create(fs::FS &fs, String directory, String fileName, String contents)
{
        File newFile;
        String absoluteFilePath = directory + fileName;
        if (fs.exists(absoluteFilePath))
                return FileStatus::AlreadyExists;
        newFile = fs.open(absoluteFilePath, "w");
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

FileStatus::Value FileManager::create(fs::FS &fs, String directory, String fileName)
{
        File newFile;
        String absoluteFilePath = directory + fileName;
        if (fs.exists(absoluteFilePath))
                return FileStatus::AlreadyExists;
        newFile = fs.open(absoluteFilePath, "w");
        if (!newFile)
        {
                newFile.close();
                return FileStatus::CanNotOpen;
        }
        newFile.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::write(fs::FS &fs, String directory, String fileName, String contents)
{
        File file;
        String absoluteFilePath = directory + fileName;

        file = fs.open(absoluteFilePath, "w");
        if (!file)
                return FileStatus::CanNotOpen;
        file.write(contents.c_str());
        file.flush();
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::write(fs::FS &fs, String directory, String fileName, uint8_t *contents, size_t fileSize)
{
        File file;
        String absoluteFilePath = directory + fileName;

        file = fs.open(absoluteFilePath, "w");
        if (!file)
                return FileStatus::CanNotOpen;
        file.write(contents, fileSize);
        file.flush();
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::append(fs::FS &fs, String directory, String fileName, String contents)
{
        File file = fs.open(directory + fileName, "a");
        file.print(contents);
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::append(fs::FS &fs, String directory, String fileName, uint8_t *contents, size_t fileSize)
{
        File file = fs.open(directory + fileName, "a");
        file.write(contents, fileSize);
        file.close();
        return FileStatus::Success;
}

FileStatus::Value FileManager::read(fs::FS &fs, String directory, String fileName, String &contents)
{
        File file;
        String absoluteFilePath = directory + fileName;
        if (!fs.exists(absoluteFilePath))
                return FileStatus::DoesNotExist;
        file = fs.open(absoluteFilePath, "r");
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

FileStatus::Value FileManager::deleteFile(fs::FS &fs, String directory, String fileName)
{
        File file;
        String absoluteFilePath = directory + fileName;
        if (!fs.exists(absoluteFilePath))
                return FileStatus::DoesNotExist;
        return fs.remove(absoluteFilePath) ? FileStatus::Success : FileStatus::Failed;
}

FileStatus::Value FileManager::isPresent(fs::FS &fs, String directory, String fileName)
{
        File file;
        String absoluteFilePath = directory + fileName;
        if (fs.exists(absoluteFilePath))
                return FileStatus::AlreadyExists;
        return FileStatus::DoesNotExist;
}

File FileManager::getFile(fs::FS &fs, String directory, String fileName)
{
        String absoluteFilePath = directory + fileName;
        return fs.open(absoluteFilePath, "r+"); // Read and write mode
}

FileStatus::Value FileManager::clear(fs::FS &fs, String directory, String fileName)
{
        File file;
        String absoluteFilePath = directory + fileName;
        file = fs.open(absoluteFilePath, "w");
        if (!file)
        {
                file.print("");
                file.close();
                return FileStatus::Success;
        }
        file.close();
        return FileStatus::Failed;
}