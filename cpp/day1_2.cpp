#include <iostream>
#include <vector>

using namespace std;

int main() {
    int mem[] = {0, 0, 0};
    for(int i = 0; i < 3; i++) cin >> mem[i];
    int cursor = 0, count = 0;
    int x;
    cin >> x;
    while(!cin.eof()) {
        if (x > mem[cursor]) count++;
        mem[cursor] = x;
        cursor = (cursor + 1) % 3;
        cin >> x;
    }
    cout << count << endl;
    return 0;
}