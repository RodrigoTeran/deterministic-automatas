#include <iostream>
#include "read.h"
#include "parse.h"
#include "regex.h"

using namespace std;

int main(int argc, char* argv[]) {

    IRegex res = read_regex();

    // Print en consola
    print_readed_regex(res);

    // Print automata
    create_automata(res);

    return 0;
}
