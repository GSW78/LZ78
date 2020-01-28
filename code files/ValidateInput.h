#ifndef Test
#include <string>
#define MAX_LENGTH 360

class ValidateInput
{
    private:
        bool checkChars(std::string input);
        bool checkSize(std::string input);
    public:
        bool checkAll(std::string input);
};
#endif
