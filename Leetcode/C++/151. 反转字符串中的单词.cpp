#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = s.size() - 1;
        for (; s[i] == ' '; ++i);
        for (; s[j] == ' '; --j);

        vector<string> arr;
        string r = "";
        for (int k = i; k <= j; ++k) {
            if (s[k] == ' ') {
                arr.push_back(r);
                r = "";
            } else {
                r += s[k];
            }
        }
        if (r != "") {
            arr.push_back(r);
        }
        string res = "";

        for (int k = arr.size() - 1; k >= 0; k--) {
            if (arr[k] != "") {
                res += arr[k];
                if (k != 0) {
                    res += " ";
                }
            }
        }
        return res;
    }
};

