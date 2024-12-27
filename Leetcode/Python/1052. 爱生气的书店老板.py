from typing import List
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        total = 0
        for i in range(len(customers)):
           if grumpy[i] == 0:
               total += customers[i]
        count = 0
        res = 0
        for right in range(len(customers)):

            count += customers[right] if grumpy[right] == 1 else 0
            
            if right < minutes -1 :
                continue
            
            res = max(res, total + count)
            
            count -= customers[right-minutes+1] if grumpy[right-minutes+1] == 1 else 0
       
            
        return res
        