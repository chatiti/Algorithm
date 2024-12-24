#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, vector<string >> m;
        for (auto it: strs) {
            string temp = it;
            sort(temp.begin(), temp.end());
            m[temp].push_back(it);
        }

        vector<vector<string >> res;
        for (auto it: m) {
            res.push_back(it.second);
        }

        return res;
    }
};