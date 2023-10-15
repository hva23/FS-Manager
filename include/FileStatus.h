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
};