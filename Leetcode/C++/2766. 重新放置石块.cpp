#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo) {
        unordered_map<int, int> m;

        for (auto it: nums) {
            m[it]++;
        }
        for (int i = 0; i < moveFrom.size(); ++i) {
            if(moveFrom[i] == moveTo[i])continue;
            m[moveTo[i]] += m[moveFrom[i]];
            m[moveFrom[i]] = 0;
        }

        vector<int> res;
        for (auto it: m) {
            if (it.second) {
                res.push_back(it.first);
            }
        }

        std::sort(res.begin(), res.end());
        return res;
    }
};