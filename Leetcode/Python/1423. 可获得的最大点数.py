from typing import List
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        ans = 0 
        s = 0
        total = sum(cardPoints)
        if k == len(cardPoints):
            return total 
        right_limit = len(cardPoints) - k 
        for right in range(len(cardPoints)):
            s += cardPoints[right]
            
            if right < right_limit-1:
                continue
            
            ans = max(ans,total - s)
            
            s -= cardPoints[right-k+1]
        return ans