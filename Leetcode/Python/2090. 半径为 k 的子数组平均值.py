from typing import List
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        arr = [0] * len(nums)
        arr[0] = nums[0]
        for i in range(1,len(nums)):  
            arr[i] = arr[i-1] + nums[i]
        res = []
        for i in range(len(nums)):
            left,right = i-k,i+k
            if left < 0 or right >= len(nums):
                res.append(-1)
            else:
                if left == 0:
                    res.append(arr[right]//(2*k+1))
                else:
                    res.append((arr[right]-arr[left-1])//(2*k+1))
        
        return res