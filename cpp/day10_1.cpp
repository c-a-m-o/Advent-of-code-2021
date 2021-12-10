#include <iostream>
#include <stack>

using namespace std;

int score(string line) {
    stack<char> s;
    for(char c : line) {
        switch (c) {
        case '(':
        case '[':
        case '{':
        case '<':
            s.push(c);
            break;
        case ')':
            if (s.empty() || s.top() != '(') return 3;
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[') return 57;
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{') return 1197;
            s.pop();
            break;
        case '>':
            if (s.empty() || s.top() != '<') return 25137;
            s.pop();
            break;
        }
    }
    return 0;
}

int main() {

    int total = 0;
    string line;

    for(;;) {
        cin >> line;
        if (cin.eof()) break;
        total += score(line);
    }
    cout << total << endl;
    return 0;
}