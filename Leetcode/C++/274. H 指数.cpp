#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int l = 0, r = 1000;
        for (; l < r;) {
            int mid = l + r + 1 >> 1;
            if (check(citations, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    bool check(vector<int> &citations, int mid) {
        int count = 0;
        for (auto it: citations) {
            if (it >= mid) {
                count++;
            }
        }
        if (count >= mid) {
            return true;
        }
        return false;
    }
};
