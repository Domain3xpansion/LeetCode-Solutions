class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        if columnNumber == 0:
            return ""
        stri = ""
        columnNumber -= 1
        rem = columnNumber % 26
        stri += chr(ord('A') + rem)
        columnNumber = columnNumber//26
        return self.convertToTitle(columnNumber) + stri