#include <iostream>
#include "LZ78.h"
#include <string>


int main()
{
    LZ78 *tree = new LZ78("abc", 2);
    std::cout<< "HI"<<std::endl;
    std::cout<< tree->getSizeOfTree() <<std::endl;
    tree->add(2,'a');
    tree->add(3,'y');
    tree->printTree();
    return 1;

}