#include "Test.h"
#include <iostream>
#include <cctype>

bool Test::checkSize(std::string input){
    if(input.length() > MAX_LENGTH)
        return false;
    return true;
}

bool Test::checkChars(std::string input){

    for(int i = 0; i < input.length(); i++){
        char char_to_check = std::tolower(input [i]);

        if(char_to_check < 'a' || char_to_check > 'z'){
            return false;
        }
    }
    return true;
}



bool Test::checkAll(std::string input){
    bool flag = true;
    std::cout<<"flag "<<flag<<"\n";
    if(!checkSize(input))
        flag = false;
    if(!checkChars(input))
        flag = false;
    return flag;
}
