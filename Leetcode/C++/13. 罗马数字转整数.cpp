#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanToInteger = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int current = romanToInteger[s[i]];

            int after = 0;
            if (i + 1 < n) {
                after = romanToInteger[s[i + 1]];
            }

            if (after > current) {
                current = after - current;
                i++;
            }
            sum += current;
        }
        return sum;
    }
};