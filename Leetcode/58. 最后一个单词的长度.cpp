#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.size() - 1;
        for (; r >= 0 && s[r] == ' '; r--);
        int l = r;
        for (; l >= 0 && s[l] != ' '; l--);
        return r - l;
    }
};