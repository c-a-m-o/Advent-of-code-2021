#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll score(string line) {
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
            if (s.empty() || s.top() != '(') return 0;
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[') return 0;
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{') return 0;
            s.pop();
            break;
        case '>':
            if (s.empty() || s.top() != '<') return 0;
            s.pop();
            break;
        }
    }
    ll res = 0;
    while (!s.empty()) {
        res *= 5;
        
        switch (s.top()) {
            case '(':
                res += 1;
                break;
            case '[':
                res += 2;
                break;
            case '{':
                res += 3;
                break;
            case '<':
                res += 4;
                break;
        }
        s.pop();
    }
    return res;
}

int main() {

    vector<ll> scores;
    string line;

    for(;;) {
        cin >> line;
        if (cin.eof()) break;
        ll s = score(line);
        if (s != 0) scores.push_back(s);
    }
    sort(scores.begin(), scores.end());
    cout << scores[scores.size() / 2] << endl;
    return 0;
}