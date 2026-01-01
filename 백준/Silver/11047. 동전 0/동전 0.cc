#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, tmp;
    cin >> n >> k;

    vector<int> coins;
    while (n--) {
        cin >> tmp;
        if (tmp > k)
            continue;

        coins.push_back(tmp);
    }

    int idx = coins.size() - 1;
    int cnt = 0;
    while (k) {
        if (coins[idx] > k) {
            idx--;
            continue;
        }

        k -= coins[idx];
        cnt++;
    }
    cout << cnt;


    return 0;
}
