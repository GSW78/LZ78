#include "LZ78.h"
#include <iostream>




LZ78::LZ78(std::string input,  int lastCharsIndex)
{
    this->text = input;
    this->lastCharsIndex = lastCharsIndex;
    this->sizeOfTree = 0; // At the beginnig there are no pairs in the array.
}



/*
@param node{int}
@param edge{char} 
Description : The function adds a new node to the tree.
*/
void LZ78::add(int node, char edge)
{
    Pair *p = new Pair(node, edge);
    tree.push_back(p);
    sizeOfTree ++;

}

int LZ78::getSizeOfTree(){
    return this->sizeOfTree;
}
void LZ78::printTree(){
    
    // Loop ont the array of the pairs, and print the node and the edge.
    for (int i = 0; i < sizeOfTree; i++)
    {
        std::cout <<"("<< tree.at(i)->getNode()  << ", " << tree.at(i)->getEdge() << ")" << std::endl;
    }
}
LZ78::~LZ78()
{
}

