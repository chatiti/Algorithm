#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        if (nums.size() == 0) {
            return vector<string>{};
        }
        vector<string> res;
        int l = nums[0];
        int r = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == r + 1) {
                r = nums[i];
            } else {
                if (l == r) {
                    res.push_back(to_string(l));
                } else {
                    res.push_back(to_string(l) + "->" + to_string(r));
                }
                l = r = nums[i];
            }
        }
        if (l == r) {
            res.push_back(to_string(l));
        } else {
            res.push_back(to_string(l) + "->" + to_string(r));
        }
        return res;
    }
};