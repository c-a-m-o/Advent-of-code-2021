#include <iostream>

using namespace std;

int main() {
    int posx = 0, posy = 0;
    string direction;
    int value;

    cin >> direction >> value;
    while(!cin.eof()) {
        if (direction == "forward") posx += value;
        if (direction == "down") posy += value;
        if (direction == "up") posy -= value;
        cin >> direction >> value;
    }

    cout << posx * posy << endl;

    return 0;
}