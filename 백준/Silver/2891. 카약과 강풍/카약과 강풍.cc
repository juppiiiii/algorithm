#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, r;
    cin >> n >> s >> r;

    vector<int> S(n + 1, 0), R(n + 1, 0);

    for (int i = 0; i < s; i++) {
        int tmp;
        cin >> tmp;
        S[tmp] = 1;
    }

    for (int i = 0; i < r; i++) {
        int tmp;
        cin >> tmp;
        R[tmp] = 1;
    }

    // 1단계: 자기 자신이 해결 가능한 경우
    for (int i = 1; i <= n; i++) {
        if (S[i] == 1 && R[i] == 1) {
            S[i] = 0;
            R[i] = 0;
        }
    }

    // 이웃에게 빌리기
    for (int i = 1; i <= n; i++) {
        if (S[i] == 1) {
            if (i - 1 >= 1 && R[i - 1] == 1) {
                R[i - 1] = 0;
                S[i] = 0;
            } else if (i + 1 <= n && R[i + 1] == 1) {
                R[i + 1] = 0;
                S[i] = 0;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (S[i] == 1) cnt++;
    }

    cout << cnt;
    return 0;
}