#include <bits/stdc++.h>

using namespace std;

//注意弹出后是b a
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> ss;
        for (auto it: tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                int a = ss.top();
                ss.pop();
                int b = ss.top();
                ss.pop();
                if (it == "+") {
                    ss.push(a + b);
                } else if (it == "-") {
                    ss.push(b - a);
                } else if (it == "*") {
                    ss.push(a * b);
                } else {
                    ss.push(b / a);
                }
            } else {
                ss.push(stoi(it));
            }
        }

        return ss.top();
    }
};