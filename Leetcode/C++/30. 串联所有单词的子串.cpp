#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int wordlen = words[0].size();
        int len = wordlen * words.size();

        map<string, int> wws;

        vector<int> res;
        for (auto it: words) {
            wws[it]++;
        }

        for (int i = 0; i + len - 1 < s.size(); ++i) {
            string target = s.substr(i, len);
            for (int j = 0; j < target.size(); j += wordlen) {
                string tt = target.substr(j, wordlen);
                if (wws[tt] == 0) {
                    break;
                }
                wws[tt]--;
            }

            res.push_back(i);
        }

        return res;
    }

};