#include <iostream>
#include <vector>

const int adj[8][2] = {
    {-1, -1}, {0, -1}, {1, -1},
    {-1,  0},          {1,  0},
    {-1,  1}, {0,  1}, {1,  1}
};

using namespace std;

bool in_bounds(int x, int y, int w, int h) {
    return x >= 0 && y >= 0 && x < w && y < h;
}

int flash(vector<vector<int>> &map, int x, int y) {
    if (map[y][x] != 10) return 0;
    int count = 1; // self
    for (auto nb : adj) {
        int newx = x + nb[0];
        int newy = y + nb[1];
        if (in_bounds(newx, newy, 10, 10)) {
            map[newy][newx]++;
            count += flash(map, newx, newy);
        }
    }
    return count;
}

int main() {
    vector<vector<int>> map(10, vector<int>(10));
    for(int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 10; j++) map[i][j] = s[j] - '0';
    }

    for(int i = 1;; i++) {
        int count = 0;
        for(int pos = 0; pos < 100; pos++) {
            map[pos / 10][pos % 10] ++;
            count += flash(map, pos % 10, pos / 10);
        }
        if (count == 100) {
            cout << i << endl;
            return 0;
        } 
        for(int pos = 0; pos < 100; pos++) {
            if (map[pos / 10][pos % 10] > 9) {
                map[pos / 10][pos % 10] = 0;
            }
        }
    }

    return 0;
}