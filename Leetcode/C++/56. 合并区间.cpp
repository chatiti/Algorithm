#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            return res;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        int l = intervals[0][0];
        int r = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            int ll = intervals[i][0];
            int rr = intervals[i][1];
            if (r < ll) {
                res.push_back(vector<int>{l, r});
                l = ll;
                r = rr;
            } else if (r >= ll) {
                r = max(rr, r);
            }
        }
        res.push_back(vector<int>{l, r});
        return res;
    }
};
