// pass
// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=855

#include <iostream>
#include <algorithm>

using namespace std;
struct milk_bucket {
    int capacity, amount;
};

milk_bucket buckets[3];

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 3; i++) {
        cin >> buckets[i].capacity >> buckets[i].amount;
    }

    for (int i = 0; i < 100; i++) {
        int start = i % 3;
        int end = (i + 1) % 3;

        int remaining_capacity = buckets[end].capacity - buckets[end].amount;
        int pour_amount = min(buckets[start].amount, remaining_capacity);

        buckets[start].amount -= pour_amount;
        buckets[end].amount += pour_amount;
    }

    cout << buckets[0].amount << endl;
    cout << buckets[1].amount << endl;
    cout << buckets[2].amount << endl;
    return 0;
}