#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> pos;

    int x;
    char comma;

    while(!cin.eof()) {
        cin >> x >> comma;
        pos.push_back(x);
    }

    sort(pos.begin(), pos.end());
    int med = pos[pos.size()/2];

    int res = 0;
    for (auto x : pos) res += abs(x - med);

    cout << res << endl;

}