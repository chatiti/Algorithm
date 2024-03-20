#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows ==1){
            return s;
        }
        vector<vector<int>> arr(numRows);
        for (int i = 0; i < s.size(); i += 2 * numRows - 2) {
            string sub;
            if (i + 2 * numRows - 2 > s.size()) {
                sub = s.substr(i);
            } else {
                sub = s.substr(i, 2 * numRows - 2);
            }
            for (int k = 0; k < sub.size(); ++k) {
                if (k < numRows) {
                    arr[k].push_back(sub[k]);
                } else {
                    arr[2 * numRows - 2 - k].push_back(sub[k]);
                }
            }
        }
        string res = "";
        for (auto str: arr) {
            for (auto it: str) {
                res += it;
            }
        }
        return res;
    }
};