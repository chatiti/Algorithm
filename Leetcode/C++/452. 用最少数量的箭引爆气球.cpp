#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() < 2) {
            return points.size();
        }
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        int l = points[0][0];
        int r = points[0][1];

        int res = 0;

        for (int i = 1; i < points.size(); ++i) {
            if (r < points[i][0]) {
                res++;
                l = points[i][0];
                r = points[i][1];
            } else {
                l = max(l, points[i][0]);
                r = min(r, points[i][1]);
            }
        }

        res++;
        return res;
    }
};