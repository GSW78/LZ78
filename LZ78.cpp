#include "LZ78.h"



LZ78::LZ78(std::string input,  int lastCharsIndex)
{
    this->text = input;
    this->lastCharsIndex = lastCharsIndex;
    tree = NULL;
}

/*
@param node{int}
@param edge{char} 
Description : The function adds a new node to the tree.
*/
void LZ78::add(int node, char edge)
{
    // Create a new node for the tree.
    Pair *newNode = new Pair(node,edge);
    
    // The first node is added to the tree: Create a new array.
    if (tree == NULL)
        tree = (Pair *)malloc(sizeof(Pair));
    // Any other case: make the array of the pairs bigger.
    else tree = (Pair *)realloc(tree, sizeof(Pair));

}
LZ78::~LZ78()
{
}
