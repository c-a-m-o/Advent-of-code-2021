#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

typedef unordered_map<string, vector<string>> graph;
typedef long long ll;

#define START "start"
#define END "end"

bool is_big_cave(string name) {
    return all_of(name.begin(), name.end(), [](unsigned char c){return isupper(c);});
}

vector<string> split_str(string s, char delimiter) {
    vector<string> res;
    string tmp;
    stringstream sstream(s);
    while(getline(sstream, tmp, delimiter)) {
        res.push_back(tmp);
    }
    return res;
}

bool process_line(graph& g) {
    string line;
    cin >> line;
    if (cin.eof()) return false;

    vector<string> nodes = split_str(line, '-');
    for(int i = 0; i < 2; i++) {
        string from = nodes[i];
        string to = nodes[1-i];
        if (!g.count(from)) g[from] = vector<string>();
        g[from].push_back(to);
    }
    return true;
}

ll nb_paths(string from, string to, graph&g, unordered_set<string>& visited, bool joker) {
    if (from == to) return 1;

    ll res = 0;
    for (string nb : g[from]) {
        if (nb == START) continue;
        if (!visited.count(nb)) {
            bool is_big = is_big_cave(nb);
            if (!is_big) visited.insert(nb);
            res += nb_paths(nb, to, g, visited, joker);
            if (!is_big) visited.erase(nb);
        } else if (joker) {
            res += nb_paths(nb, to, g, visited, false);
        }
    }
    
    return res;
}

int main() {
    graph g;
    while(process_line(g));
    unordered_set<string> visited;

    cout << nb_paths(START, END, g, visited, true) << endl;
}