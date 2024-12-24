#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int> &nums) {
        int a = 0;
        int b = 0;
        for (auto it: nums) {
            if (it >= 0 && it <= 9) {
                a += it;
            } else if (it >= 10 && it <= 99) {
                b += it;
            }
        }

        if (a == b) {
            return false;
        }
        return true;
    }
};