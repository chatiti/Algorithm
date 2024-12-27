class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        count = 0
        res = k
        for right in range(len(blocks)):
            if blocks[right] == 'W':
                    count += 1
                    
            if  right < k - 1:
                continue
            else:
                res = min(res, count)
                count -= 1 if blocks[right - k +1 ] == 'W' else 0
        
        return res 