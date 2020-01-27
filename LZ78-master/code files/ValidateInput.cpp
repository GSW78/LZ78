#include "ValidateInput.h"
#include <iostream>
#include <cctype>

//function to check size of input
bool ValidateInput::checkSize(std::string input){
    if(input.length() > MAX_LENGTH)
        return false;
    return true;
}
//function to check that string contains only lower case letters
bool ValidateInput::checkChars(std::string input){
    for(int i = 0; i < input.length(); i++){
        char char_to_check = std::tolower(input [i]);
        if(char_to_check < 'a' || char_to_check > 'z'){
            return false;
        }
    }
    return true;
}
//function to validate input
bool ValidateInput::checkAll(std::string input){
    bool flag = true;
    if(!checkSize(input))
        flag = false;
    if(!checkChars(input))
        flag = false;
    return flag;
}
