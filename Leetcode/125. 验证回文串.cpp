#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> c;
        for (auto it: s) {
            if (isalnum(it)) {
                c.push_back(::tolower(it));
            }
        }
        if (c.size() == 0) {
            return true;
        }
        int i = 0, j = c.size() - 1;
        while (i < j) {
            if (c[i] != c[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};