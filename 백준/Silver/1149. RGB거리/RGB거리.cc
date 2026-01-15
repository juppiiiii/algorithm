#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(3, 0));
    vector<vector<int>> cache(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> tmp;
            cost[i][j] = tmp;
        }
    }

    // cache[i][0]: i 번째 집을 칠할 때까지의 최소 비용 (0: 빨강, 1: 초록, 2: 파랑)
    cache[0][0] = cost[0][0], cache[0][1] = cost[0][1], cache[0][2] = cost[0][2];
    for (int i = 1; i < n; i++) {
        cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + cost[i][0];
        cache[i][1] = min(cache[i - 1][2], cache[i - 1][0]) + cost[i][1];
        cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + cost[i][2];
    }

    cout << *min_element(cache[n - 1].begin(), cache[n - 1].end());


    return 0;
}