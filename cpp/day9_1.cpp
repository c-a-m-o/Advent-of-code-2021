#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int neighbors[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool in_bounds(int x, int y, int w, int h) {
    return x >= 0 && y >= 0 && x < w && y < h;
}

int main() {
    string line;
    vector<string> map;
    for(;;) {
        cin >> line;
        if (cin.eof()) break;
        map.push_back(line);
    }

    int h = map.size();
    int w = map[0].size();

    int res = 0;

    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            int bigger = 0;
            for(auto delta: neighbors) {
                int newx = x + delta[0];
                int newy = y + delta[1];
                if (in_bounds(newx, newy, w, h)) {
                    bigger += map[newy][newx] > map[y][x];
                } else {
                    bigger++;
                }
            }
            if (bigger == 4) {
                res += map[y][x] - '0' + 1;
            }
        }
    }

    cout << res << endl;

}