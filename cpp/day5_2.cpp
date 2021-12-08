#include <iostream>
#include <vector>

#define SIZE 1000

using namespace std;

int main() {
    int count = 0;
    vector<vector<int>> map(SIZE, vector<int>(SIZE, 0));
    int x1, y1, x2, y2;
    while(scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != -1) {
        int dx = (x1 - x2 < 0) - (x2 - x1 < 0);
        int dy = (y1 - y2 < 0) - (y2 - y1 < 0);
        int x = x1;
        int y = y1;
        do {
            map[y][x] += 1;
            if (map[y][x] == 2) count ++;
            x += dx;
            y += dy;
        } while (x != x2 + dx || y != y2 + dy);
    }
    cout << count << endl;

}