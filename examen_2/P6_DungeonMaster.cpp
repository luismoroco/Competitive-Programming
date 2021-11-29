#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/dungeon

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define oo 1000000000
typedef int long long ll;

class Solution {
public:
    ll d[40][40][40];
    ll color[40][40][40];
    ll rows, cols, levels;
    char dungeon[40][40][40];
    ll head, tail;
    struct cell {
        ll lev;
        ll row;
        ll col;
    };
    struct cell quee[30000];

    void 
    space() {
        char c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    void 
    pushh(ll l, ll i, ll j) {
        quee[tail].lev = l;
        quee[tail].row = i;
        quee[tail].col = j;
        color[l][i][j] = GRAY;
        ++tail;
    }

    void 
    dequee(ll *l, ll *i, ll *j) {
        *l = quee[head].lev;
        *i = quee[head].row;
        *j = quee[head].col;
        color[*l][*i][*j] = BLACK;
        ++head;
    }

    void 
    visit(ll level, ll row, ll col, ll distance) {
        if (level < 0 || level >= levels || row < 0 || row >= rows || col < 0 ||
            col >= cols || dungeon[level][row][col] == '#' ||
            color[level][row][col] != WHITE)
            return;
        d[level][row][col] = distance;
        pushh(level, row, col);
    }

    ll 
    read_case() {
        ll l, i;
        scanf("%d %d %d", &levels, &rows, &cols);
        if (rows == 0 && cols == 0 && levels == 0) return 0;
        space();
        for (l = 0; l < levels; ++l) {
            for (i = 0; i <= rows; ++i) {
                fgets(dungeon[l][i], 40, stdin);
            }
        }
        return 1;
    }

    void 
    solve_case() {
        struct cell start;
        ll l, i, j, newd;

        for (l = 0; l < levels; ++l) {
            for (i = 0; i < rows; ++i) {
                for (j = 0; j < cols; ++j) {
                    color[l][i][j] = WHITE;
                    d[l][i][j] = oo;
                    if (dungeon[l][i][j] == 'S') {
                        start.lev = l;
                        start.row = i;
                        start.col = j;
                    }
                }
            }
        }

        head = tail = 0;
        visit(start.lev, start.row, start.col, 0);
        while (head != tail) {
            dequee(&l, &i, &j);
            if (dungeon[l][i][j] == 'E') break;
            newd = d[l][i][j] + 1;
            visit(l, i - 1, j, newd);
            visit(l, i + 1, j, newd);
            visit(l, i, j + 1, newd);
            visit(l, i, j - 1, newd);
            visit(l + 1, i, j, newd);
            visit(l - 1, i, j, newd);
        }


        if (dungeon[l][i][j] == 'E')
            printf("Escaped in %d minute(s).\n", d[l][i][j]);
        else
            printf("Trapped!\n");
    }
};

int
main(ll argc, char const *argv[]) {
    Solution s;
    while (s.read_case()) s.solve_case();
    return 0;
}
