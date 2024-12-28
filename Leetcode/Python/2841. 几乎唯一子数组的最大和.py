from typing import List
class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        dist = {}
        sum = 0
        count = 0
        res = 0
        
        for right in range(len(nums)):
            if dist.get(nums[right], 0) == 0:
                count += 1
            dist[nums[right]] = dist.get(nums[right], 0) + 1
            sum += nums[right]

            if right < k-1:
                continue
            
            if count >= m:
                res = max(res,sum)
            
            dist[nums[right-k+1]] -= 1
            sum -= nums[right-k+1]
            if dist.get(nums[right-k+1], 0) == 0 :
                count -= 1
            
        return res    