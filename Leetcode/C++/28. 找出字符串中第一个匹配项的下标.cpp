#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        for (; i < haystack.size(); ) {
            if (haystack[i] == needle[j]) {
                ++j;
                ++i;
            } else {
                i = i-j+1;
                j = 0;
            }
            if (j == needle.size()) {
                return i - needle.size();
            }
        }
        return -1;
    }
};