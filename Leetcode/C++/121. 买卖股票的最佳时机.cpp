#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min = 1e9;
        int pre = 0;
        for (auto it: prices) {
            if (it < min) {
                min = it;
            } else {
                pre = max(pre,it-min);
            }
        }
        return pre;
    }
};