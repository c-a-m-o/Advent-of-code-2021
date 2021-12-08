#include <iostream>
#include <sstream>
#include <vector>

#define BOARD_SIZE 5
#define MAX_NUM 100

using namespace std;

vector<int> get_numbers() {
    vector<int> res;

    string line;
    getline(cin, line);
    stringstream s(line);

    int x;
    char comma;

    do {
        s >> x >> comma;
        res.push_back(x);
    } while (!s.eof());

    return res;
}

int main() {

    vector<int> numbers = get_numbers();
    string line;

    // pos[i*100+j] :
    // -1 if j is not in board i
    // the position of j in board i otherwise
    // position / BOARD_SIZE : row
    // position % BOARD_SIZE : col
    vector<int> pos;
    vector<int> sum_pts; // Sum of unchecked cells in a board
    int x;
    int nb_boards = 0;

    cin >> x;
    while(!cin.eof()) {
        pos.resize(pos.size() + MAX_NUM, -1);
        sum_pts.push_back(0);
        int offset = nb_boards * MAX_NUM;

        for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
            pos[offset+x] = i;
            sum_pts[nb_boards] += x;
            cin >> x;
        }
        nb_boards++;
    }
    // checked_on_<row|col>[i*BOARD_SIZE+j] :
    // nb of numbers checked on <row|col> j of board i
    vector<int> checked_on_row(nb_boards*BOARD_SIZE, 0);
    vector<int> checked_on_col(nb_boards*BOARD_SIZE, 0);

    for (int n : numbers) {
        for (int b = 0; b < nb_boards; b++) {
            int offset = b * MAX_NUM;
            int p = pos[offset + n];
            if (p != -1) {
                int offset2 = b * BOARD_SIZE;
                int row = p / BOARD_SIZE;
                int col = p % BOARD_SIZE;
                checked_on_row[offset2 + row]++;
                checked_on_col[offset2 + col]++;
                sum_pts[b] -= n;
                if (checked_on_row[offset2+row] == BOARD_SIZE || checked_on_col[offset2+col] == BOARD_SIZE) {
                    cout << sum_pts[b] * n << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No bingo" << endl;
    
    return 0;
}