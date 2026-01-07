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
    stairs.push_back(0);
    while (n--) {
        cin >> tmp;
        stairs.push_back(tmp);
    }

    vector<int> cache = vector<int>(stairs.size(), 0);

    if (stairs.size() == 2) {
        cout << stairs[1];
        return 0;
    }


    if (stairs.size() == 3) {
        cout << stairs[1] + stairs[2];
        return 0;
    }


    cache[1] = stairs[1], cache[2] = stairs[1] + stairs[2], cache[3] = max(stairs[1], stairs[2]) + stairs[3];
    for (int i = 4; i < stairs.size(); i++) {
        cache[i] = max(stairs[i] + stairs[i - 1] + cache[i - 3], stairs[i] + cache[i - 2]);
    }

    // for (int& stair : stairs) {
    //     printf("%d ", stair);
    // }
    // cout << endl;
    // for (int& i : cache) {
    //     printf("%d ", i);
    // }

    cout << cache[stairs.size() - 1];
    return 0;
}