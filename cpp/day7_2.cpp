#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> pos;

    int x;
    char comma;
    int sum = 0;
    int minx = -1;
    int maxx = -1;

    while(!cin.eof()) {
        cin >> x >> comma;
        pos.push_back(x);
        sum += x;
        if (minx == -1 || minx > x) {
            minx = x;
        }
        if (maxx == -1 || maxx < x) {
            maxx = x;
        }
    }

    int min_res = -1;
    

    for (int target = minx; target < maxx; target++) {
        int res = 0;
        for (int x : pos) {
            int delta = abs(x-target);
            res += delta * (delta+1) / 2;
        }
        if (min_res == -1 || min_res > res) {
            min_res = res;
        }
    }

    cout << min_res << endl;

}