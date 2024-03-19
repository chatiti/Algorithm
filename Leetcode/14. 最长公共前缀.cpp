#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    string longestCommonPrefix(vector<string> &strs) {
//        map<string, int> m;
//        for (auto s: strs) {
//            for (int i = 0; i <= s.size(); ++i) {
//                m[s.substr(0, i)]++;
//            }
//        }
//        string res = "";
//        for (auto it: m) {
//            if (it.second == strs.size()) {
//                if (it.first.size() > res.size()) {
//                    res = it.first;
//                }
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs.empty() ? "" : strs[0];
        for (string s : strs)
            while (s.find(res) != 0) res = res.substr(0, res.length() - 1);
        return res;
    }
};