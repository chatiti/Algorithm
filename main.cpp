#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0, j = 1;
        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        for (; j < n;) {
           if (nums[i] == nums[j]){
               j++;
           } else{
               nums[++i] = nums[j++];
           }
        }
        return i+1;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << solution.removeDuplicates(nums1);
    return 0;
}