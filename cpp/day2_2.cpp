#include <iostream>

using namespace std;

int main() {
    int posx = 0, depth = 0, aim = 0;
    string direction;
    int value;

    cin >> direction >> value;
    while(!cin.eof()) {
        if (direction == "forward") {
            posx += value;
            depth += value * aim;
        }
        if (direction == "down") aim += value;
        if (direction == "up") aim -= value;
        cin >> direction >> value;
    }

    cout << posx * depth << endl;

    return 0;
}