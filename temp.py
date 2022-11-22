class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_possible = 0
        last_ocurrencies = {}
        result = 0
        for i in range(len(s)):
            try:
                possible = last_ocurrencies[s[i]]
                if possible == last_possible:
                    result = result if i - last_possible < result else i-last_possible
                    last_possible += 1
                if possible > last_possible:
                    result = result if i - last_possible < result else i-last_possible
                    last_possible = i
                    
                last_ocurrencies[s[i]] = i
            except:
                last_ocurrencies[s[i]] = i
                    
        result = result if len(s) - last_possible < result else len(s)-last_possible
        return result
