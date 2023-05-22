#include <iostream>
#include "read.h"
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]) {

    IRegex res = read_regex();
    print_readed_regex(res);

	WListGraph<char, int> wmg;
	
	wmg.addEdge('A', 'B', 1);
	wmg.addEdge('A', 'A', 4);
	wmg.addEdge('B', 'C', 1);
	wmg.addEdge('B', 'D', 1);
	wmg.addEdge('C', 'E', 1);
	wmg.addEdge('D', 'C', 1);
	wmg.addEdge('E', 'D', 1);
	
	std::cout << wmg.toString();
	
	std::map<char, int> wedges = wmg.getConnectionFrom('D');
	std::map<char, int>::iterator witr;
	
	std::cout << "B ->\t";
	for (witr = wedges.begin(); witr != wedges.end(); witr++) {
		std::cout << "(" << witr->first << "," << witr->second << ")\t";
	}

    return 0;
}
