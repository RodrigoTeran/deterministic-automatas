#include <iostream>
#include "read.h"
#include "parse.h"

using namespace std;

int main(int argc, char* argv[]) {

    IRegex res = read_regex();

    // Print en consola
    print_readed_regex(res);
    
    // Parsear a grafo
    parse_regex(res);

    return 0;
}
