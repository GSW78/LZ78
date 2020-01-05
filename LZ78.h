#ifndef LZ78
#define LZ78
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
    Pair* max_code_recuresive(int i, std::string text, Pair* parent, int n_son, int* currLength);


    
public:
    LZ78(std::string input, int lastCharsIndex);
    void encode(std::string input);
    Pair* getPairs();
    void printTree();
    Pair* maxCode(std::string text, int* currLength);
    int maxCodeLength();
    int getSizeOfTree();
    void add(int node, char edge, int n_son);
    ~LZ78();
};
#endif