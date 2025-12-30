#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

// 2% 에서 계속 틀림
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, start, end;
    cin >> n;

    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        times.emplace_back(start, end);
    }

    sort(times.begin(), times.end(), [] (pair<int, int> a, pair<int, int> b) {
        if ((a.second - a.first) == (b.second - b.first)) return a.second < b.second;
        if (a.first == b.first) return a.second < b.second;
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int answer = 1;
    end = times[0].second;

    int i = 1;
    while (i < n) {
        if (end <= times[i].first) {
            end = times[i].second;
            answer++;
        }
        i++;
    }

    cout << answer;
    return 0;
}
