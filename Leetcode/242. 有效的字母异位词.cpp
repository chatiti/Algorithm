#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        map<char, int> a;
        for (auto it: s) {
            a[it]++;
        }

        for (auto it: t) {
            if (a[it] == 0) {
                return false;
            }
            a[it]--;
        }

        return true;
    }
};