#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> names(n + 1);
    unordered_map<string, int> nameToIndex;

    for (int i = 1; i <= n; i++) {
        cin >> names[i];
        nameToIndex[names[i]] = i;
    }

    while (m--) {
        string q;
        cin >> q;

        if (isdigit(q[0])) {
            int idx = stoi(q);
            cout << names[idx] << '\n';
        } else {
            cout << nameToIndex[q] << '\n';
        }
    }

    return 0;
}