#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include "LZ78.h"
#include "Test.h"

int main(int argc, char *argv[])
{
	//Get input from file
	std::ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile) {
		std::cout << "Unable to open file";
		exit(1);
	}
	std::stringstream strStream;
	strStream << inFile.rdbuf();
	std::string str = strStream.str();
	inFile.close();
	
	//validate input
	Test test;
	if(!test.checkAll(str)){
		std::cout << "input: "<< str <<" is in incorrect format.";
	exit(1);
	}

	//create tree, encode, print
	LZ78 *tree = new LZ78("a", 2);
	tree->encode(str);
	tree->printTree();
	
	return 1;
}
