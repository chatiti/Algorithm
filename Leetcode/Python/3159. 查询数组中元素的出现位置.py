from typing import List
class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        count = 0
        arr = [0] * (len(nums) +1 )
        for idx , n  in enumerate(nums):
            if n == x :
                count += 1
                arr[count] = idx 
        
        res = []
        for i in queries:
            if i  <= count:
                res.append(arr[i])
            else:
                 res.append(-1)

        return res