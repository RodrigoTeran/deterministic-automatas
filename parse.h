#include <iostream>
#include "graph.h"
#include <string>

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
bool is_char_in_alphabet(IRegex rx, char ch) {
    for (int i = 0; i < rx.size_alphabet; i++) {
        string string_regex_alphabet = rx.alphabet[i];
        char char_regex_alphabet = string_regex_alphabet.at(0);
        if (ch == char_regex_alphabet) return true;
    };
    return false;
};

void print_stack(string* stack, int size_stack) {
    for (int i = 0; i < size_stack; i++) {
        cout << i << ") " << stack[size_stack] << endl;
    };
};

void pardse_regex(IRegex rx) {
    int regex_size = rx.regex.size();

    cout << "regex_size: " << regex_size << endl;

    // Crear stacks
    string* stack_operators = new string[regex_size];
    int size_stack_operators = 0;

    string* stack_alphabet = new string[regex_size];
    int size_stack_alphabet = 0;

    // Iterate regex
    for (int i = 0; i < regex_size; i++) {
        char char_regex = rx.regex[i];
        string string_regex = "";
        string_regex += char_regex;

        cout << "string_regex: " << string_regex << endl;
        cout << "size_stack_alphabet: " << size_stack_alphabet << endl;

        if (is_char_in_alphabet(rx, char_regex)) {
            // Meter en stack de alfabeto
            stack_alphabet[size_stack_alphabet] = string_regex;
            size_stack_alphabet++;
        } else {
            // Meter en stack de operadores
            stack_operators[size_stack_operators] = string_regex;
            size_stack_operators++;
        };
    };

    print_stack(stack_operators, size_stack_operators);
    print_stack(stack_alphabet, size_stack_alphabet);
      
    // WListGraph<char, int> wlg;
	
	// wlg.addEdge('A', 'B', 1);
	// wlg.addEdge('A', 'A', 4);
	// wlg.addEdge('B', 'C', 1);
	// wlg.addEdge('B', 'D', 1);
	// wlg.addEdge('C', 'E', 1);
	// wlg.addEdge('D', 'C', 1);
	// wlg.addEdge('E', 'D', 1);
	
	// std::cout << wlg.toString();
	
	// std::map<char, int> wedges = wlg.getConnectionFrom('D');
	// std::map<char, int>::iterator witr;
	
	// std::cout << "B ->\t";
	// for (witr = wedges.begin(); witr != wedges.end(); witr++) {
	// 	std::cout << "(" << witr->first << "," << witr->second << ")\t";
	// };
};
