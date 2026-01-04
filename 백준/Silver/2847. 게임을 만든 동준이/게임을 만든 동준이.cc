#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp;
    vector<int> scores;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        scores.push_back(tmp);
    }

    int cnt = 0;
    for (int i = n - 1; i > 0; i--) {
        if (scores[i - 1] >= scores[i]) {
            int differ = scores[i - 1] - scores[i] + 1;
            scores[i - 1] -= differ;
            cnt += differ;
        }
    }

    cout << cnt;

    return 0;
}
