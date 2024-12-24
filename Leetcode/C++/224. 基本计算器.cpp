#include <bits/stdc++.h>

using namespace std;

//拆括号，还需要再刷
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> ss;
        ss.push(1);
        int sign = 1;
        int res = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
            }else if (s[i] == '+') {
                sign = ss.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ss.top();
                i++;
            } else if (s[i] == '(') {
                ss.push(sign);
                i++;
            } else if (s[i] == ')') {
                ss.pop();
                i++;
            } else {
                long  n = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    n = n * 10 + s[i] - '0';
                    i++;
                }
                res += n * sign;
            }
        }

        return res;
    }
};
