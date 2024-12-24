#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
//        for (int i = 0; i < nums.size(); ++i) {
//            for (int j = i + 1; j < nums.size(); ++j) {
//                if (nums[i] + nums[j] == target) {
//                    return vector<int>{i, j};
//                }
//            }
//        }
//        return vector<int>{};



        map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i]) == 1) {
                return vector<int>{i, m[target - nums[i]]};
            } else {
                m[nums[i]] = i;
            }
        }
        return vector<int>{};
    }
};