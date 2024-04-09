#include <bits/stdc++.h>

using namespace std;


//找到一段序列最小的值，开始+1，看set中是否有
//使用unordered_set，否则超时
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0;

        unordered_set<int> s;

        for (auto it: nums) {
            s.insert(it);
        }

        for (auto it: nums) {
            if (!s.count(it - 1)) {
                int count = 1;
                while (s.count(it + count)) {
                    count++;
                }
                res = max(res, count);
            }

        }
        return res;
    }
};
