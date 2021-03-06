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

/*
Description : The function returns the size of the nodes of the tree
*/
int LZ78::getSizeOfTree(){
    return this->sizeOfTree;
}

/*
Description : The function prints the tree
*/
void LZ78::printTree(){
    
    // Loop on the array of the pairs, and print the node and the edge.
    for (int i = 0; i < sizeOfTree; i++)
    {
        std::cout <<"("<< tree.at(i)->getNode()  << ", " << tree.at(i)->getEdge() << ", " << tree.at(i)->getN_son() << ")" << std::endl;
    }
}

/*
@param index{int}
@param text{string} 
@param parent{Pair*} 
@param n_son{int}
@param currLength{int*}
Description : The recursive function returns the maximum length of substring (from the text)
*/
Pair* LZ78::max_code_recuresive (int i, std::string text, Pair* parent, int n_son, int* currLength) {
    if (text == "") 
        return new Pair(-1, '*', -1);

    char curr = text[0];
    int j;
    *(currLength) = text.length()-1;
    
    for (j=0; j<sizeOfTree; j++) {

        Pair* pointer = NULL;

        try {
             pointer = tree.at(j);
        } catch (const std::out_of_range& e) {
            return parent;
        }
        if (pointer->getNode() == n_son && pointer->getNode() >= i && pointer->getEdge() == curr ) {
            parent = pointer;    
            return max_code_recuresive(i+1, text.substr(1, text.length()), parent, parent->getN_son(), currLength);  
        }    
    }
    return parent;
}

/*
@param text{string}
@param currLength{int*}
Description : Warpper function which returns the maximum length of substring (from the text) - calls the recursive function
*/
Pair* LZ78::maxCode(std::string text, int* currLength) {
    // the tree is empty
    if (this->tree.empty()) {
        *(currLength)-=1;
        return NULL;
    }

    Pair* parent = max_code_recuresive (0, text, NULL, 0, currLength);
    return parent;
}

/*
@param input{string} 
Description : The main function - creates the Lempel-Ziv tree
*/
void LZ78::encode(std::string input){
    
    int son = 0;
    int pos = -1;
    int currWordLength = 0, currLength = input.length(), prevLength = input.length(), father;
    char nodeLetter;
    Pair* fatherNode;
    string copiedInput = input;

    while(currLength > 0)
    {
                
        son++;
        prevLength = copiedInput.length();
        fatherNode = maxCode(copiedInput, &currLength);
        

        if (fatherNode == NULL) {
            add (0,copiedInput[0], son); // add a new node to the root
            copiedInput = copiedInput.substr(1, copiedInput.length());
            pos++;
            continue;
        }

        if (fatherNode->getNode() == -1)
            return;
		
        currWordLength = prevLength - currLength;

        copiedInput = copiedInput.substr(currWordLength);
        pos += currWordLength;
        nodeLetter = input[pos];
        father = fatherNode->getNode() + 1;
        add(father, nodeLetter, son);   // after finding the the substring add it to the tree 
    }
}

LZ78::~LZ78() {}
