#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        for (; i < s.size() && j < t.size();) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }else{
                j++;
            }
        }
        if (i == s.size()) { return true; }
        return false;
    }
};