#include <math.h>

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int& num : nums) {
            vector<int> dividers = {1, num};
            for (int i = 2; i < int(std::sqrt(num)) + 1; i++) {
                if (num % i == 0) {
                    dividers.push_back(i);
                    if (int(num / i) != i) {
                        dividers.push_back(int(num / i));
                    }

                    if (dividers.size() > 4) {
                        dividers = {};
                        break;
                    }
            
                }
            }
            if (dividers.size() == 4) {
                sum += accumulate(dividers.begin(), dividers.end(), 0);
            }
        }
        return sum;
    }
};