// pass
// problem url: https://open.kattis.com/problems/basketballoneonone

#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 0, b = 0;
    string record;
    cin >> record;
    for (int i = 0; i < record.size(); i += 2) {
        if (record[i] == 'A') {
            a += record[i+1] - '0';
        } else {
            b += record[i+1] - '0';
        }
    }
    if (a > b) {
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }
    return 0;
}
