class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        remleadtrailspaces = s.strip()
        words = remleadtrailspaces.split(' ')
        return len(words[-1])