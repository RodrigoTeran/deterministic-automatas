#include <iostream>
#include "utils.h"

using namespace std;

string parse_regex(const IRegex& regex) {
    string parsed_string;

    for (int i = 0; i < regex.size_alphabet; i++) {
        char current_char = regex.alphabet[i];

        if (isalpha(current_char) && i + 1 < regex.size_alphabet && isalpha(regex.alphabet[i + 1])) {
            parsed_string += current_char;
            parsed_string += '.';
        } 
        
        else if ((current_char == '*' || current_char == '+') && i + 1 < regex.size_alphabet && isalpha(regex.alphabet[i + 1])) {
            parsed_string += current_char;
            parsed_string += '.';
        } 
        
        else if ((current_char == '*' || current_char == '+') && i + 1 < regex.size_alphabet && regex.alphabet[i + 1] == '(') {
            parsed_string += current_char;
            parsed_string += '.';
        } 
        
        else {
            parsed_string += current_char;
        }
    }

    return parsed_string;
}
