#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <string>
#include "utils.h"

using namespace std;

void print_readed_regex(IRegex res) {
    cout << "=== Printing readed regex ===" << endl;
    cout << "size_alphabet: " << res.size_alphabet << endl;
    cout << "alphabet: " << endl;
    for (int i = 0; i < res.size_alphabet; i++) {
        cout << i << ") " << res.alphabet[i] << endl;
    }
    cout << "regex: " << res.regex << endl;
};

IRegex read_regex(){
    ifstream MyReadFile("tests/regex.txt"); 
    string myText;
    IRegex res;

    // Obtener línea por línea
    int counter = 0;
    while (getline (MyReadFile, myText)) {
        if (counter == 0) {
            // Abecedario
            int size_alphabet = myText.size();
            res.alphabet = new string[size_alphabet];
            res.size_alphabet = size_alphabet;

            for (int i = 0; i < size_alphabet; i++) {
                res.alphabet[i] = myText[i];
            }
        } else {
            // Regex
            res.regex = myText;
        }
        counter++;
    }

    // Cerrar el archivo
    MyReadFile.close();

    return res;
};