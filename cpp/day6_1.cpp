#include <iostream>
#include <vector>

#define STEPS 80

using namespace std;

int main() {
    vector<int> times(9, 0);
    int count = 0;

    int x;
    char comma;

    do {
        cin >> x >> comma;
        count ++;
        times[x]++;
    } while(!cin.eof());

    int cursor = 0;

    // cout << "[ ";
    // for (int x : times) cout << x << " ";
    // cout << "] " << endl;

    for (int i = 0; i < STEPS; i++) {
        int reg_cursor = (cursor + 7) % 9;
        int new_cursor = (cursor + 1) % 9;
        count += times[cursor];
        times[reg_cursor] += times[cursor];
        cursor = new_cursor;
        // cout << "[ ";
        // for (int x : times) cout << x << " ";
        // cout << "] ";
        // cout << i+1 << " " << count << endl;
    }

    cout << count << endl;
    
    return 0;
}