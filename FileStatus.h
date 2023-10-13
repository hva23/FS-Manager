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
        String stringValueOf[5]{
            "Success",
            "DoesNotExist",
            "AlreadyExists",
            "CanNotOpen",
            "Failed"};
};