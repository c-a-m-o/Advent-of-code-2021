#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> lines;
    string line;
    while(getline(cin, line)) lines.push_back(line);
    vector<int> mem(lines.size(), 0);
    
    string oxygen_gen;
    string life_sup;

    vector<string> candidates = lines;
    for(int i = 0; i < candidates[0].size() && candidates.size() > 1; i++) {
        int ones = 0;
        for (int j = 0; j < candidates.size(); j++)
            if (candidates[j][i] == '1') ones++;
        char most_common = (ones * 2 >= candidates.size()) ? '1' : '0';
        candidates.erase(remove_if(candidates.begin(), candidates.end(),
            [most_common, i](string l){return l[i] != most_common;}),
            candidates.end());
    }
    oxygen_gen = candidates[0];
    
    candidates = lines;
    for(int i = 0; i < candidates[0].size() && candidates.size() > 1; i++) {
        int ones = 0;
        for (int j = 0; j < candidates.size(); j++)
            if (candidates[j][i] == '1') ones++;
        char least_common = (ones * 2 >= candidates.size()) ? '0' : '1';
        candidates.erase(remove_if(candidates.begin(), candidates.end(),
            [least_common, i](string l){return l[i] != least_common;}),
            candidates.end()
        );
    }
    life_sup = candidates[0];

    int og = 0;
    int ls = 0;
    for (int i = 0; i < oxygen_gen.size(); i++) {
        og <<= 1;
        ls <<= 1;
        if (oxygen_gen[i] == '1') og++;
        if (life_sup[i] == '1') ls++;
    }
    cout << og * ls << endl;

    return 0;
}