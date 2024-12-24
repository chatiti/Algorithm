#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        int i = 0;
        while (i < s.size()) {
            if (ss.empty()) {
                ss.push(s[i]);
                i++;
                continue;
            }
            auto n = s[i];
            auto top = ss.top();
            if (n == '(' || n == '[' || n == '{') {
                ss.push(s[i]);
            } else {
                if (n == ')' && top != '(') {
                    return false;
                }
                if (n == ']' && top != '[') {
                    return false;
                }
                if (n == '}' && top != '{') {
                    return false;
                }
                ss.pop();
            }
            i++;
        }

        return ss.size() == 0;
    }
};
