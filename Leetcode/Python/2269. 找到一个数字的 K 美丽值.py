class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        res = 0
        for i in range(0,len(str(num)) - k +1  ):
            sub = int(str(num)[i:i+k])
            if sub != 0 and num % sub == 0:
                res += 1
        
        return res