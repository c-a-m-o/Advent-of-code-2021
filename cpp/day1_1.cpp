#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count = 0;
    int prev, x;
    cin >> prev >> x;
    while (!cin.eof()) {
        count += x > prev;
        prev = x;
        cin >> x;
    }
    cout << count << endl;
    return 0;
}