#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int i = 0, j = n - 1;
        int count = 0;
        for (; i <= j;)
        {
            for (; i < n && nums[i] != val; i++)
                ;
            for (; j >= 0 && nums[j] == val; j--)
                ;
            if (i <= j)
            {
                swap(nums[i], nums[j]);
                count++;
            }
        }
        return i;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    nums.push_back(2);
    int val = 3;
    int len = solution.removeElement(nums, val);
    cout << len;
    return 0;
}