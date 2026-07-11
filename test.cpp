#include <iostream>
using namespace std;

void moveRow(int row[4]) {
    int temp[4] = {0};
    int idx = 0;
    for (int i = 0; i < 4; i++) {
        if (row[i] != 0) temp[idx++] = row[i];
    }
    for (int i = 0; i < 3; i++) {
        if (temp[i] != 0 && temp[i] == temp[i + 1]) {
            temp[i] *= 2;
            temp[i + 1] = 0;
            i++;
        }
    }
    int res[4] = {0};
    idx = 0;
    for (int i = 0; i < 4; i++) {
        if (temp[i] != 0) res[idx++] = temp[i];
    }
    for (int i = 0; i < 4; i++) row[i] = res[i];
}

void moveLeft(int grid[4][4]) {
    for (int i = 0; i < 4; i++) moveRow(grid[i]);
}

void moveRight(int grid[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            int t = grid[i][j];
            grid[i][j] = grid[i][3 - j];
            grid[i][3 - j] = t;
        }
        moveRow(grid[i]);
        for (int j = 0; j < 2; j++) {
            int t = grid[i][j];
            grid[i][j] = grid[i][3 - j];
            grid[i][3 - j] = t;
        }
    }
}

void moveUp(int grid[4][4]) {
    for (int j = 0; j < 4; j++) {
        int col[4];
        for (int i = 0; i < 4; i++) col[i] = grid[i][j];
        moveRow(col);
        for (int i = 0; i < 4; i++) grid[i][j] = col[i];
    }
}

void moveDown(int grid[4][4]) {
    for (int j = 0; j < 4; j++) {
        int col[4];
        for (int i = 0; i < 4; i++) col[i] = grid[i][j];
        for (int i = 0; i < 2; i++) {
            int t = col[i];
            col[i] = col[3 - i];
            col[3 - i] = t;
        }
        moveRow(col);
        for (int i = 0; i < 2; i++) {
            int t = col[i];
            col[i] = col[3 - i];
            col[3 - i] = t;
        }
        for (int i = 0; i < 4; i++) grid[i][j] = col[i];
    }
}

int main() {
    int grid[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char move;
        cin >> move;
        if (move == 'L' || move == 'l') moveLeft(grid);
        else if (move == 'R' || move == 'r') moveRight(grid);
        else if (move == 'U' || move == 'u') moveUp(grid);
        else if (move == 'D' || move == 'd') moveDown(grid);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j) cout << ' ';
            cout << grid[i][j];
        }
        cout << '\n';
    }
    return 0;
}
