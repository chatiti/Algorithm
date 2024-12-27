# class Solution:
#     def isSubstringPresent(self, s: str) -> bool:
#         substrings = set()
#         for i in range(len(s)-1):
#             substrings.add(s[i:i+2])
#         reversed_s = s[::-1]
#         for i in range(len(s)-1):
#             if reversed_s[i:i+2] in substrings:
#                 return True
#         return False

class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        substrings = set()
        for i in range(len(s)-1):
            substrings.add(s[i]+s[i+1])
            if s[i+1] + s[i] in substrings:
                return True 
    
        return False