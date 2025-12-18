// pass 100%
// problem url https://usaco.org/index.php?page=viewproblem2&cpid=891

#include <iostream>
#include <algorithm>
using namespace std;

int N;
const int maxn = 105;
struct step {
    int a, b, g;
};
step steps[maxn];

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> steps[i].a >> steps[i].b >> steps[i].g;
    }

    // simulation
    int ans = -1;
    for (int i = 0; i < 3; i++) {
        int board[3] = {0, 0, 0};
        board[i] = 1;
        int tempans = 0;
        for (int j = 0; j < N; j++) {
            // swap cups
            int temp = board[steps[j].a - 1];
            board[steps[j].a - 1] = board[steps[j].b - 1];
            board[steps[j].b - 1] = temp;
            if (board[steps[j].g - 1] == 1) {
                tempans ++;
            }
        }
        ans = max(ans, tempans);
    }
    cout << ans << endl;
    return 0;
}
