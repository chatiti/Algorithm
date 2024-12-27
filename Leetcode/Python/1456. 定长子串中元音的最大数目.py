class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        res = 0 
        arr = [0] * (len(s)+1)
        arr[0] = 0
        for i in range(1, len(s)+1):
            if s[i-1] in vowels:
                arr[i] = arr[i-1] + 1
            else:
                arr[i] = arr[i-1]
        print(arr)
    
        for i in range(1,len(s)+1):
            if i -k  >= 0:
                res = max(res, arr[i] - arr[i-k])
        
        return res
    
s = "abciiidef"
k = 3
print(Solution().maxVowels(s,k))
    