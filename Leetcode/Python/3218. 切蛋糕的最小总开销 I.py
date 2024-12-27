from typing import List
class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        cost = 0
        row,clo = 1,1
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)
        i,j = 0,0
        while i<len(horizontalCut) or  j<len(verticalCut):
            if i<len(horizontalCut) and j<len(verticalCut):
                if horizontalCut[i] > verticalCut[j]:
                    cost += horizontalCut[i]*clo
                    row +=1
                    i+=1
                else:
                    cost += verticalCut[j]*row
                    clo +=1
                    j+=1    
            elif i<len(horizontalCut):
                cost += horizontalCut[i]*clo
                row +=1
                i+=1
            else:
                cost += verticalCut[j]*row
                clo +=1
                j+=1    
        return cost
    
sol = Solution()
m = 3
n = 2
horizontalCut = [1,3]
verticalCut = [5]
print(sol.minimumCost(m,n,horizontalCut,verticalCut))