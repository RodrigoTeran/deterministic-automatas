#include <string>
#include <map>

using namespace std;

struct IRegex {
    string* alphabet;
    int size_alphabet;
    string regex;
};

struct State {
    int id;
    map<char, int> transitions;
};