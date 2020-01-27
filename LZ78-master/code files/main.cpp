#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include "LZ78.h"
#include "ValidateInput.h"

int main(int argc, char *argv[])
{
	//get input from file
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
	ValidateInput validate;
	if(!validate.checkAll(str)){
		std::cout << "Input: "<< str <<" is in incorrect format.";
		exit(1);
	}

	//create tree
	LZ78 *tree = new LZ78("a", 2);
	//encode
	tree->encode(str);
	//print tree
	tree->printTree();
	
	return 1;
}
