class Solution:
    def romanToInt(self, s: str) -> int:
        num = 0
        roman_dic = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        for i in range(len(s)-1):
            if roman_dic[s[i]] < roman_dic[s[i+1]]:
                num -= roman_dic[s[i]]
            else:
                num += roman_dic[s[i]]
        num += roman_dic[s[-1]]
        return num