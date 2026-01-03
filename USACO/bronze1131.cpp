#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int N, L;
int c[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    sort(c, c + N, greater<int>());
    int h = 0;
    for (int i = 1; i <= N; i++) {
        if (c[i - 1] >= i) {
            h = i;
        } else if (c[i] + 1 == i) {
            h = i;
        } else break;
    }
    return 0;
}