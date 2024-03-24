#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        map<char, int> m;
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            m[s[j]] ++;
            while (m[s[j]] > 1) {
                m[s[i++]]--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};