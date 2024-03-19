#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        int arr[n];
        fill(arr, arr + n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0 || ratings[i] <= ratings[i - 1]) {
                arr[i] = 1;
            } else {
                arr[i] = arr[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1 || ratings[i] <= ratings[i + 1]) {
                arr[i] = max(1, arr[i]);
            } else {
                arr[i] = max(arr[i], arr[i + 1] + 1);
            }
        }

        int sum = 0;
        for (auto it: arr) {
            sum += it;
        }

        return sum;
    }
};

