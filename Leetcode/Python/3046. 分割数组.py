# from typing import List
# class Solution:
#     def isPossibleToSplit(self, nums: List[int]) -> bool:
#         dist = {}
#         for x in nums:
#             if dist.get(x, 0) >=2 :
#                 return False
#             dist[x] = dist.get(x, 0) + 1
#         return True

from typing import List
from collections import Counter
class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        return Counter(nums).most_common(1)[0][1]<=2