#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> ss;
        map<char, int> tt;
        for (auto it: t) {
            tt[it]++;
        }
        int len = 1e9;
        int sl = -1;
        int i = 0, j = 0;
        while (j < s.size()) {
            ss[s[j]]++;

            while (i <= j && check(ss, tt)) {
                if (len > j - i + 1) {
                    len = j - i + 1;
                    sl = i;
                }
                ss[s[i++]]--;
            }
            j++;
        }
        if (len > 1e9 / 2) {
            return "";
        }
        return s.substr(sl, len);
    }

    bool check(map<char, int> &ss, map<char, int> &tt) {
        for (auto it: tt) {
            if (it.second > ss[it.first]) {
                return false;
            }
        }
        return true;
    }
};
