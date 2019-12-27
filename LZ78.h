#ifndef LZ78
#include "Pair.h"
#include <string>

class LZ78
{
private:
    // The pointer to the tree.
    Pair * tree ;
    // The text for the tree.
    std:: string text;
    //The end of the text.
    int lastCharsIndex;
    // The length of the array tree.
    int sizeOfTree;

    std::string maxCode();
    int maxCodeLength();
    void add(int node, char edge);
    

public:
    LZ78(std::string input, int lastCharsIndex);
    void encode();
    Pair* getPairs();
    void printTree();
    ~LZ78();
};
#endif