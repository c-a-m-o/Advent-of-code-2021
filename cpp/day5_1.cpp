#include <iostream>
#include <vector>

#define SIZE 1000

using namespace std;

int main() {
    int count = 0;
    vector<vector<int>> map(SIZE, vector<int>(SIZE, 0));
    int x1, y1, x2, y2;
    while(scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != -1) {
        int dx = x1 < x2 ? 1 : -1;
        int dy = y1 < y2 ? 1 : -1;
        if (x1 == x2 || y1 == y2) {
            for (int x = x1; x != x2 + dx; x += dx) {
                for (int y = y1; y != y2 + dy; y += dy) {
                    map[y][x] += 1;
                    if (map[y][x] == 2) count ++;
                }
            }
        }
    }
    cout << count << endl;

}