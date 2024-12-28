from typing import List
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        dist = {}
        sum = 0
        res = 0 
        diff = 0
        for righr in range(len(nums)):
            if dist.get(nums[righr], 0) == 0:
                diff += 1
            dist[nums[righr]] = dist.get(nums[righr], 0) + 1
            sum += nums[righr]
            
            if righr < k -1 :
                continue
            
            if diff == k :
                res = max(res,sum)
                
            dist[nums[righr-k+1]] -=1
            sum -= nums[righr-k+1]
            if dist[nums[righr-k+1]] == 0 :
                diff -=1
        return res
            
            
print(Solution().maximumSubarraySum([1,2,3,4,5], 3))