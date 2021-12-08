#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// a and b must be sorted
int nb_common_letters(string a, string b) {
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < a.size() && j < b.size()) {
        int delta = a[i] - b[j];
        if (delta <= 0) {
            i++;
        }
        if (delta >= 0) {
            j++;
        }
        if (delta == 0) {
            count++;
        }

    }
    return count;
}

unordered_map<string, int> corres() {
    unordered_map<string, int> res;

    vector<string> input(10);
    vector<string> num_to_s(10, "");

    for(int i = 0; i < 10; i++) {
        cin >> input[i];
        sort(input[i].begin(), input[i].end());
        if (input[i].size() == 2) num_to_s[1] = input[i];
        if (input[i].size() == 4) num_to_s[4] = input[i];
        if (input[i].size() == 3) num_to_s[7] = input[i];
        if (input[i].size() == 7) num_to_s[8] = input[i];
        // 2, 3, 5 : 5 segments
        // 0, 6, 9 : 6 segments
    }

    if (cin.eof()) return res;
    res[num_to_s[1]] = 1;
    res[num_to_s[4]] = 4;
    res[num_to_s[7]] = 7;
    res[num_to_s[8]] = 8;
    
    
    // 9
    for(string s : input) {
        if (s.size() == 6 && nb_common_letters(s, num_to_s[4]) == 4) {
            num_to_s[9] = s;
            res[s] = 9;
            break;
        }
    }
    // 0
    for(string s : input) {
        if (res.count(s)) continue;
        if (s.size() == 6 && nb_common_letters(s, num_to_s[1]) == 2) {
            num_to_s[0] = s;
            res[s] = 0;
            break;
        }
    }
    // 6
    for (string s : input) {
        if (!res.count(s) && s.size() == 6) {
            num_to_s[6] = s;
            res[s] = 6;
            break;
        }
    }

    // 3
    for(string s : input) {
        if (s.size() == 5 && nb_common_letters(s, num_to_s[1]) == 2) {
            num_to_s[3] = s;
            res[s] = 3;
            break;
        }
    }

    // 5
    for(string s : input) {
        if (res.count(s)) continue;
        if (s.size() == 5 && nb_common_letters(s, num_to_s[9]) == 5) {
            num_to_s[5] = s;
            res[s] = 5;
        }
    }
    // 2
    for(string s : input) {
        if (!res.count(s)) {
            num_to_s[2] = s;
            res[s] = 2;
        }
    }

    return res;

}


int main() {

    int res = 0;

    for(;;) {
        unordered_map<string, int> m = corres();
        if (m.size() == 0) break;
        string digit;
        cin >> digit; // skip |

        int num = 0;
        for(int i = 0; i < 4; i++) {
            cin >> digit;
            sort(digit.begin(), digit.end());
            num = num * 10 + m[digit];
        }
        res += num;
    }

    cout << res << endl;

    return 0;
}