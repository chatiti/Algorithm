#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int count = 0;
        while (count < 100) {
            int temp = 0;
            while (n != 0) {
                temp += pow(n % 10, 2);
                n /= 10;
            }
            n = temp;

            if (n == 1) {
                return true;
            }

            count++;
        }

        return false;
    }
};