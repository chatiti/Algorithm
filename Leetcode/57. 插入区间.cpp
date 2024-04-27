#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        if (intervals.size() == 0) {
            return vector<vector<int>>{newInterval};
        }
        vector<vector<int>> arr;
        for (auto it: intervals) {
            arr.push_back(it);
        }
        arr.push_back(newInterval);
        sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        int l = arr[0][0], r = arr[0][1];
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i][0] > r) {
                res.push_back(vector<int>{l, r});
                l = arr[i][0];
                r = arr[i][1];
            } else if (arr[i][0] >= l) {
                r = max(r, arr[i][1]);
            }
        }

        res.push_back(vector<int>{l, r});
        return res;
    }
};