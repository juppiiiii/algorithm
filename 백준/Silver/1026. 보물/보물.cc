#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp;
    vector<int> a, b;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), [](int a, int b) {
        return a > b;
    });



    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }
    cout << s;

    return 0;
}
