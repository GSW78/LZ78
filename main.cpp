#include <iostream>
#include "LZ78.h"
#include <string>


int main()
{
    LZ78 *tree = new LZ78("a", 2);
    // std::cout<< "HI"<<std::endl;
    // std::cout<< tree->getSizeOfTree() <<std::endl;

    // tree->add(0,'a', 1);
    // tree->add(1,'c', 2);
    // tree->add(0,'g', 3);
    // tree->add(2,'g', 4);
    // tree->add(1,'t', 5);
    // tree->add(5,'b', 6);
    // tree->add(6,'g', 7);
    // tree->add(3,'a', 8);
    // tree->add(5,'a', 9);

    tree->encode("aacgacgat");
    tree->printTree();

    // tree->maxCode("atb");

    return 1;
}