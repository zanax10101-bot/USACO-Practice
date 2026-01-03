// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=1155
// algorithm used: 
// Run Length Encoding RLE optimization method O(N)
// Brute force method O(N^2) and O(N^3), however this would not pass all test cases
// pass

/*
notes
- a substring is lonely if there is only one G or H in the substring
- example GHGHG
- GHG HGH GHG length 3 substring
- GHGH HGHG length 4 substring
- GHGHG length 5 substring
- lonely substring: GHG(x2), HGH
*/

/*
explanation to line 65 and 67
- 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 100005;
int N;
string s;
long long ans = 0;
long long cnt = 0;
vector <long long> runs;

int main() {
    cin >> N;
    cin >> s;
    // step 1: we compress the string in to "runs"
    // example: HHGHHH becomes [2, 1, 3]
    for (int i = 0; i < N; i++) {
        if (i == 0) { 
            // this would avoid s[i - 1] have memory errors
            cnt++;
        } else if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            runs.push_back(cnt);
            cnt = 1;
        }
    }
    runs.push_back(cnt); // this would push back the last group
    for (int i = 0; i < runs.size(); i++) {
        // avoid memory errors if index is the leftmost and rightmost element
        long long L = 0;
            if (i > 0) {
                L = runs[i - 1];
            }
            long long R = 0;
            if (i < runs.size() - 1) {
                R = runs[i + 1];
            }
        if (runs[i] == 1) {
            // note we use 0LL becaue L and R are long long and 0 normally is a int
            // in order for max to work, we need to have arguments with the same type
            ans += (L * R) + max(0LL, L-1) + max(0LL, R-1); 
        } else {
            ans += max(0LL, L - 1) + max(0LL, R - 1);
        }
    }
    cout << ans << endl;
    return 0;
}