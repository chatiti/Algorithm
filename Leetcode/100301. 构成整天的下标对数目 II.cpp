#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int> &hours) {
        unordered_map<int, int> m;
        for (auto it: hours) {
            m[it % 24]++;
        }

        long long res = 0;
        for (int i = 0; i < 24; ++i) {
            if (i == 0 || i == 12) {
                res += (long long) m[i] * (long long)(m[i] - 1) / 2;
            } else {
                res += 24 - i > i ? (long long)m[i] * (long long)m[24 - i] : 0;
            }
        }
        return res;
    }
};
