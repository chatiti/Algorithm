#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.length();
        unordered_set<char> a = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < s.length(); ++i) {
            if (a.count(s[i])) {
                return true;
            }
        }

        return false;
    }
};