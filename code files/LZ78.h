#ifndef LZ78
#include "Pair.h"
#include <string>
#include <vector> //for the tree

class LZ78
{
	private:
		//the tree
		std::vector <Pair *> tree; 
		//the text for the tree
		std:: string text;
		//the end of the text
		int lastCharsIndex;
		//the length of the array tree
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
