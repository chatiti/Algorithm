from typing import List
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums)):
            count += 1 if  nums[i] == 1 else 0
        
        if count == 0 or count == len(nums):
            return 0
        res = count

        windows_sum = 0
        nums.extend(nums)
        for right in range(len(nums)):
            windows_sum += nums[right]
            
            if right < count -1:
                continue
            
            res  = min(res, count - windows_sum)
            
            windows_sum -= nums[right - count + 1]
            
        return res
            