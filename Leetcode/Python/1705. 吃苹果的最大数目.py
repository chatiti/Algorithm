class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        n = len(apples)
        heap = []
        day = 0 
        ans = 0
        while day < n or heap:
            if day < n and apples[day] > 0:
                heapq.heappush(heap, (days[day] + day, apples[day]))
            
            while heap and heap[0][0] <= day:
                heapq.heappop(heap)
            
            if heap:
                a,b = heapq.heappop(heap)
                ans += 1
                if b > 1:
                    heapq.heappush(heap, (a, b-1))
                    
            day += 1
        return ans
    
    
print(Solution().eatenApples([1,2,3,5,2], [3,2,1,4,2])) 
