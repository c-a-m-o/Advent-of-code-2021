#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    int count = 0;

    for(;;) {
        // Before the | and the | itself
        for(int i = 0; i < 11; i++) cin >> s;
        if (cin.eof()) break;
        for(int i = 0; i < 4; i++) {
            cin >> s;
            int size = s.size();
            if (size == 2 || size == 3 || size == 4 || size == 7) count++;
        }
    }

    cout << count << endl;

    return 0;
}