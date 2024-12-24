#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nonSpecialCount(int l, int r) {

        int res = 0;
        for (int i = l; i <= r; ++i) {
            int count = 0;
            for (int j = 1; j <= sqrt(i); ++j) {
                if (i % j == 0) {
                    count++;
                }
                if (count > 2) {
                    res++;
                    break;
                }
            }
        }
        return res;

    }
};