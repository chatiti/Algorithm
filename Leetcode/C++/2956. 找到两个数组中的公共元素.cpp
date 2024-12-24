#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> a;
        unordered_set<int> b;

        for (auto it: nums1) {
            a.insert(it);
        }
        for (auto it: nums2) {
            b.insert(it);
        }

        vector<int> res = {0, 0};

        for (auto it: nums1) {
            if (b.count(it)) {
                res[0]++;
            }
        }

        for (auto it: nums2) {
            if (a.count(it)) {
                res[1]++;
            }
        }
        return res;
    }
};