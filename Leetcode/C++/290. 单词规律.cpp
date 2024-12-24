#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if (s[s.size() - 1] != ' ') {
            s += " ";
        }
        vector<string> arr;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                arr.push_back(s.substr(i, j - i));
                i = j + 1;
            }
        }
        map<char, string> a;
        map<string, char> b;


        int n = pattern.size();
        int m = arr.size();
        if (n != m) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (a.count(pattern[i]) == 0 && b.count(arr[i]) == 0) {
                a[pattern[i]] = arr[i];
                b[arr[i]] = pattern[i];
            } else {
                if (a[pattern[i]] != arr[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};