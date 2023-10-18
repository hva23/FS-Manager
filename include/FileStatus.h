#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef FILE_STATUS_H
#define FILE_STATUS_H
#endif

class FileStatus
{
public:
        enum Value
        {
                Success,
                DoesNotExist,
                AlreadyExists,
                CanNotOpen,
                Failed
        };
        static String stringValueOf(FileStatus::Value status)
        {
                switch (status)
                {
                case FileStatus::Success:
                        return "Success";
                case FileStatus::DoesNotExist:
                        return "DoesNotExist";
                case FileStatus::AlreadyExists:
                        return "AlreadyExists";
                case FileStatus::CanNotOpen:
                        return "CanNotOpen";
                case FileStatus::Failed:
                        return "Failed";
                default:
                        return "";
                }
        }
};