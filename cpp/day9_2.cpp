#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int neighbors[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool in_bounds(int x, int y, int w, int h) {
    return x >= 0 && y >= 0 && x < w && y < h;
}

int basin(int x, int y, vector<string> &map, vector<vector<int>> &mem, vector<int> &sizes) {
    // cout << x << " " << y << endl;
    int basin_id = mem[y][x];
    if (sizes.size() > basin_id) {
        sizes[basin_id]++;
    } else {
        sizes.push_back(1);
    }

    int h = map.size();
    int w = map[0].size();
    
    for (auto nb : neighbors) {
        int newx = x + nb[0];
        int newy = y + nb[1];
        if (in_bounds(newx, newy, w, h) && mem[newy][newx] == -1 && map[newy][newx] != '9') {
            mem[newy][newx] = basin_id;
            basin(newx, newy, map, mem, sizes);
        }
        
    }
    return sizes[basin_id];
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

    vector<int> sizes;
    vector<vector<int>> mem(h, vector<int>(w, -1));

    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            if (map[y][x] != '9' && mem[y][x] == -1) {
                mem[y][x] = sizes.size();
                basin(x, y, map, mem, sizes);
            }
        }
    }

    sort(sizes.begin(), sizes.end());
    int nb_basins = sizes.size();

    cout << sizes[nb_basins-1] * sizes[nb_basins-2] * sizes[nb_basins-3] << endl;

}