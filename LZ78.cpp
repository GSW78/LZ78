#include "LZ78.h"
#include <iostream>

using namespace std;



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
void LZ78::add(int node, char edge, int n_son)
{
    Pair *p = new Pair(node, edge, n_son);
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
        std::cout <<"("<< tree.at(i)->getNode()  << ", " << tree.at(i)->getEdge() << ", " << tree.at(i)->getN_son() << ")" << std::endl;
    }
}
LZ78::~LZ78()
{
}


Pair* LZ78::max_code_recuresive (int i, std::string text, Pair* parent, int n_son, int* currLength) {
    

    if (text == "") 
        return new Pair(-1, '*', -1);

    char curr = text[0];    // ?? text[i]
    int j;
    *(currLength) = text.length()-1;        /////////////////////////////////////////////
    
    // std::cout << "iter " << i << " Text is << " << text << " >> curr-char is " << curr << std::endl;    

    for (j=0; j<sizeOfTree; j++) {

        Pair* pointer = NULL;

        try {
            /*Pair**/ pointer = tree.at(j);   // at(j)??? int j=i ????
        } catch (const std::out_of_range& e) {
            // std::cout << "here" << std::endl;
            return parent;
        }


        // std::cout << "iter " << i << " NODE in tree " << tree.at(j)->getEdge() << std::endl;  //??????????

        if (pointer->getNode() == n_son && pointer->getNode() >= i && pointer->getEdge() == curr ) {
            // std::cout << "IF: iter " << i << " Current text: " << text << " text to send: " << text.substr(/*i+1*/1, text.length())  << std::endl;
            parent = pointer;
            
            return max_code_recuresive(i+1, text.substr(/*i+*/1, text.length()), parent, parent->getN_son(), currLength);  
        }

          
    }

    // std::cout << "HERE" << std::endl;

    // if (parent != NULL)
    //     std::cout << parent->getNode() << ", " << parent->getEdge() << std::endl;
    // else
    //     std::cout << "PARENT IS ROOT" << std::endl;    
           
    return parent;
}

