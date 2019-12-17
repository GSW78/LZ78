#include "LZ78.h"



LZ78::LZ78(std::string input,  int lastCharsIndex)
{
    this->text = input;
    this->lastCharsIndex = lastCharsIndex;
    tree = NULL;
}

LZ78::~LZ78()
{
}
