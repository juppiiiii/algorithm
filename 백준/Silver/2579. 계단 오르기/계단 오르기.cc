#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp;
    cin >> n;

    vector<int> stairs;
    while (n--) {
        cin >> tmp;
        stairs.push_back(tmp);
    }

    if (stairs.size() == 1) {
        cout << stairs[0];
        return 0;
    }

    // cache[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓 값
    vector<vector<int>> cache(stairs.size(), vector<int>(3, 0));

    cache[0][1] = stairs[0];
    cache[1][1] = stairs[1];
    cache[1][2] = stairs[0] + stairs[1];

    for (int i = 2; i < stairs.size(); i++) {
        cache[i][1] = max(cache[i - 2][1], cache[i - 2][2]) + stairs[i];
        cache[i][2] = cache[i - 1][1] + stairs[i];
    }

    cout << max(cache[stairs.size() - 1][1], cache[stairs.size() - 1][2]);

    return 0;
}