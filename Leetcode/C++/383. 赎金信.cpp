#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> a;
        for (auto it: magazine) {
            a[it]++;
        }


        for (auto it: ransomNote) {
            if (a[it] == 0) {
                return false;
            } else {
                a[it]--;
            }
        }
        return true;
    }
};