#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int n = s.length();
        s += "1";
        vector<int> arr;
        arr[0] = s[0] == '0' && s[1] == '1' ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            arr[i] = s[i] == '0' && s[i + 1] == '1' ? arr[i - 1] + 1 : arr[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                res += arr[n - 1] - arr[i];
            }
        }

        return res;
    }
};