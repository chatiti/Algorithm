from typing import List
class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        res = []
        count = set()
        colors , balls = {},{}
        for q in queries:
            ball,color = q[0],q[1]
            old_color = balls.get(ball,0)
            if old_color!= 0:  
                colors[old_color] -= 1
                if colors[old_color] == 0:
                    count.remove(old_color)
                
            colors[color] = colors.get(color,0) + 1
            balls[ball] = color
            if color not in count:
                count.add(color)
            
            res.append(len(count))
            
        return res
            