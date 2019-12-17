#include "Pair.h"
#include <string>

class LZ78
{
private:
    Pair tree [];



public:
    LZ78(std::string input);
    void encode(std::string input);
    Pair[] getPairs();

    ~LZ78();
};

