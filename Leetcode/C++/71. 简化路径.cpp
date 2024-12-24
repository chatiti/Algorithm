#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ss;
        int i = 1;
        while (i < path.size()) {
            string op = "";
            while (i < path.size() && path[i] != '/') {
                op += path[i];
                i++;
            }
            if (op == ".") {

            } else if (op == "..") {
                if (ss.size()) {
                    ss.pop();
                }

            } else if (op == "") {

            } else {
                ss.push(op);
            }
            i++;
        }

        string res = "";
        if (ss.size() == 0) {
            return "/";
        }

        while (ss.size()) {
            res = "/" + ss.top() + res;
            ss.pop();
        }
        return res;
    }
};