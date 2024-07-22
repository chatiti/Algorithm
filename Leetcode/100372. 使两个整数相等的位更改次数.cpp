#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int a = n %2;
            int b = k %2;
            if (a == 1 && b == 0) {
                res++;
            }else if(a == 0 && b == 1){
                return -1;
            }
            n = n >> 1;
            k = k >> 1;
        }

        return res;
    }
};
