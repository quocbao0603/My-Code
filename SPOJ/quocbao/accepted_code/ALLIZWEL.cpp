#include <bits/stdc++.h>
#define MAX 101
using namespace std;

const string term = "ALLIZZWELL";
int R, C;
bool found;
int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};
bool visited[MAX][MAX];
char table[MAX][MAX];

bool isValid(int r, int c) {
    return r >= 0 && c >= 0 && r < R && c < C;
}

void DFS(int sr, int sc, int count) {
    if (count == term.size()) {
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int r = sr + dr[i];
        int c = sc + dc[i];

        if (isValid(r, c) && table[r][c] == term[count] && !visited[r][c]) {
            visited[r][c] = true;
            DFS(r, c, count + 1);
            visited[r][c] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> R >> C;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> table[i][j];
                visited[i][j] = false;
            }
        }

        found = false;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (table[i][j] == term[0] && !found) {
                    DFS(i, j, 1);
                }
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}