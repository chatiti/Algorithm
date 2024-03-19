#include <bits/stdc++.h>

using namespace std;

//分别找左和右最高的，取最小值减去当前高度

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int arr[n];
        int sum = 0;
        fill(arr, arr + n, 0);
        int left[n];
        int right[n];
        fill(left, left + n, 0);
        fill(right, right + n, 0);

        left[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left[i] = max(height[i], left[i - 1]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = max(height[i], right[i + 1]);
        }

        arr[0] = arr[n - 1] = 0;
        for (int i = 1; i < n - 1; ++i) {
            arr[i] =  min(left[i], right[i]) - height[i];
            sum += arr[i];
        }

        return sum;
    }
};