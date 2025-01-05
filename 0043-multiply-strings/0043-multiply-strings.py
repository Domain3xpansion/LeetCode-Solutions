class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        inum1 = int(num1)  #Converting from string to int
        inum2 = int(num2)  #Converting from string to int
        res = inum1 * inum2   
        sres = str(res)  #Converting from int to res as the question demands
        return sres
        