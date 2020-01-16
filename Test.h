#ifndef Test
#include <string>
#define MAX_LENGTH 360

class Test
{
    private:
        bool checkChars(std::string input);
        bool checkSize(std::string input);
    public:
        //Test(std::string input);
        bool checkAll(std::string input);
};
#endif
