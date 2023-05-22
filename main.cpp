#include <iostream>
#include "utils.h"

using namespace std;

int main(int argc, char* argv[]) {

    IRegex res = read_regex();
    print_readed_regex(res);
    
	return 0;
}
