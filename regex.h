#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>

using namespace std;

void create_automata(IRegex rx) {
    string regex = rx.regex;

    stack<int> stateStack;
    vector<State> states;

    int stateCount = 0;
    for (char c : regex) {
        if (c == '(' || c == '|' || c == '+') {
            stateStack.push(stateCount);
        }
        else if (c == ')') {
            int prevState = stateStack.top();
            stateStack.pop();

            if (!stateStack.empty() && regex[stateStack.top()] == '|') {
                int orState = stateStack.top();
                stateStack.pop();

                State newState;
                newState.id = stateCount;
                newState.transitions['E'] = prevState;
                states.push_back(newState);

                states[orState].transitions['E'] = stateCount;

                stateStack.push(orState);
                stateStack.push(stateCount);
                stateCount++;
            }
            else {
                State newState;
                newState.id = stateCount;
                newState.transitions['E'] = prevState;
                states.push_back(newState);

                stateStack.push(stateCount);
                stateCount++;
            }
        }
        else if (c == '*') {
            int prevState = stateStack.top();
            stateStack.pop();

            State newState;
            newState.id = stateCount;
            newState.transitions['E'] = prevState;
            newState.transitions['E'] = stateCount;
            states.push_back(newState);

            stateStack.push(stateCount);
            stateCount++;
        }
        else {
            State newState;
            newState.id = stateCount;
            newState.transitions[c] = stateCount + 1;
            states.push_back(newState);

            stateStack.push(stateCount + 1);
            stateCount++;
        }
    }

    cout << "\nTabla de transiciones:\n\n";
    cout << "\t";
    set<char> alphabet;
    for (const auto& state : states) {
        for (const auto& transition : state.transitions) {
            if (transition.first != 'E') {
                alphabet.insert(transition.first);
            }
        }
    }
    for (char c : alphabet) {
        cout << c << "\t";
    }
    cout << endl;

    for (const auto& state : states) {
        cout << state.id << " ";
        for (char c : alphabet) {
            cout << "\t";
            if (state.transitions.count(c) > 0) {
                cout << state.transitions.at(c);
            }
        }
        cout << endl;
    }
}