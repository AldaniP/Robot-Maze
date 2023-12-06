#include <iostream>
#include <vector>

using namespace std;

void printArena(const vector<vector<char> >& arena) {
    for (size_t i = 0; i < arena.size(); ++i) {
        const vector<char>& row = arena[i];
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
        }
        cout << endl;
    }
}

bool isValidMove(int row, int col, int N, int M, const vector<vector<char> >& arena) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

int main() {
    int N, M;
    cin >> N >> M;

    if (N < 2 || N > 100 || M < 2 || M > 100) {
        cerr << "Input tidak sesuai batasan" << endl;
        return 1;
    }

    vector<vector<char> > arena(N, vector<char>(M));
    int start_row, start_col, finish_row, finish_col;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arena[i][j];
            if (arena[i][j] == '*') {
                start_row = i;
                start_col = j;
            } else if (arena[i][j] == '$') {
                finish_row = i;
                finish_col = j;
            }
        }
    }

    int num_instructions;
    cin >> num_instructions;

    if (num_instructions < 1 || num_instructions > 100) {
        cerr << "Input tidak memenuhi" << endl;
        return 1;
    }

    string result_message = "Robot Tidak Mencapai Finish";
    vector<string> wrong_instructions;

    for (int i = 0; i < num_instructions; ++i) {
        char instruction;
        cin >> instruction;

        int new_row = start_row, new_col = start_col;

        switch (tolower(instruction)) {
            case 'w': --new_row; break;
            case 'a': --new_col; break;
            case 's': ++new_row; break;
            case 'd': ++new_col; break;
        }

        if (isValidMove(new_row, new_col, N, M, arena)) {
            if (arena[new_row][new_col] == 'o') {
                wrong_instructions.push_back(to_string(i + 1) + " Robot Menabrak Obstacle");
            } else {
                arena[start_row][start_col] = '#';
                start_row = new_row;
                start_col = new_col;
                arena[start_row][start_col] = '*'; // Set '*' at the new location
            }
        } else {
            wrong_instructions.push_back(to_string(i + 1) + " Robot Menabrak Tembok");
        }

        if (start_row == finish_row && start_col == finish_col) {
            result_message = "Robot Mencapai Finish";
            break;
        }
    }

    cout << endl;

    // Print error
    for (size_t i = 0; i < wrong_instructions.size(); ++i) {
        cout << wrong_instructions[i] << endl;
    }

    // Print arena
    printArena(arena);

    cout << result_message << endl;

    return 0;
}
