#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string line;
    vector<int> mem;

    while(getline(cin, line)) {
        if (mem.size() < line.size()) mem.resize(line.size(), 0);
        for(int i = 0; i < line.size(); i++) {
            mem[i] += line[i] == '0' ? -1 : 1;
        }
    }

    int mem_size = mem.size();
    int gamma = 0;
    int epsilon = 0;
    for (int i = 0; i < mem_size; i++) {
        gamma <<= 1;
        epsilon <<= 1;
        if (mem[i] > 0) {
            gamma++;
        } else {
            epsilon++;
        }
    }
    
    cout << gamma * epsilon << endl;

    return 0;
}