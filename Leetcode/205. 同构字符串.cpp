#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n != m) {
            return false;
        }
        map<char, char> a;
        map<char, char> b;
        for (int i = 0; i < n; ++i) {
            if (a.count(s[i]) == 0 && b.count(t[i]) == 0) {
                a[s[i]] = t[i];
                b[t[i]] = s[i];
            } else {
                if (a[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};