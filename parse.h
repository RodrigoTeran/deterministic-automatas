#include <iostream>
#include "utils.h"

using namespace std;

string parse_regex(const IRegex& res) {
    string parsed_string;

    for (int i = 0; i < res.size_alphabet; i++) {
        string current_char = res.alphabet[i];
        string current_char1 = res.alphabet[i+1];
        char c_char = current_char[0];
        char c_char1 = current_char1[0];

        if (isalpha(c_char) && i + 1 < res.size_alphabet && isalpha(c_char1)) {
            parsed_string += current_char;
            parsed_string += '.';
        } 
        
        else if ((c_char == '*' || c_char == '+') && i + 1 < res.size_alphabet && isalpha(c_char1)) {
            parsed_string += c_char;
            parsed_string += '.';
        } 
        
        else if ((c_char == '*' || c_char == '+') && i + 1 < res.size_alphabet && c_char1 == '(') {
            parsed_string += c_char;
            parsed_string += '.';
        } 
        
        else {
            parsed_string += c_char;
        }
    }

    return parsed_string;
}
