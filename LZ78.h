#ifndef LZ78
#include "Pair.h"
#include <string>
#include <vector> // For the tree
class LZ78
{
private:
    // The tree.
    std::vector <Pair *> tree; 
    // The text for the tree.
    std:: string text;
    //The end of the text.
    int lastCharsIndex;
    // The length of the array tree.
    int sizeOfTree;

    
public:
    LZ78(std::string input, int lastCharsIndex);
    void encode();
    Pair* getPairs();
    void printTree();
    std::string maxCode();
    int maxCodeLength();
    int getSizeOfTree();
    void add(int node, char edge);
    ~LZ78();
};
#endif