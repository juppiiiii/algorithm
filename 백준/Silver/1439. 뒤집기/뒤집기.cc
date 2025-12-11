#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string given;
    cin >> given;

    vector<int> divider;
    vector<int> count = {0, 0};
    divider.push_back(given[0]);
    int divider_length = 0;
    count[given[0] - 48]++;

    for (int i = 1; i < given.length(); i++) {
        if (divider[divider_length] != given[i]) {
            divider.push_back(given[i]);
            divider_length++;
            count[given[i] - 48]++;
        }
    }
    cout << *min_element(count.begin(), count.end());

    return 0;
}
