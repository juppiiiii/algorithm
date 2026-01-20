#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y, w, s;
    cin >> x >> y >> w >> s;
    
    long long answer = 0;
    long long diagonal = min(x, y);
    long long straight = abs(x - y);
    long long case1 = diagonal * s + straight * w;
    
    long long case2 = diagonal * s + straight * s;
    if (straight % 2 == 1) {
        case2 = diagonal * s + (straight - 1) * s + w;
    }
    long long case3 = (x + y) * w;
    
    answer = min({case1, case2, case3});
    
    cout << answer;
    
    return 0;
    
}