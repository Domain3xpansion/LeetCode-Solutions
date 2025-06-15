class Solution {
public:
    bool freqchar(string s){
        vector<int> freq(26, 0);
        for(auto ch: s){
            freq[ch-'a']++;
            if(freq[ch-'a']>1)
                return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        if(s == goal)
            return freqchar(s);
        vector<int> nums;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=goal[i])
                nums.push_back(i);
        }
        if(nums.size() != 2)
            return false;
        swap(s[nums[0]], s[nums[1]]);
        return s == goal;
    }
};