class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*unordered_map<int, int> hashmap;
        for(int x : nums){
            hashmap[x]++;
        }
        for(auto pair:hashmap){
            if(pair.second > (nums.size()/2))
                return pair.first;
        }
        return -1;*/
        int cnt = 0;
        int el;
        for(int x : nums){
            if(cnt == 0) {
                cnt = 1;
                el = x;
            }else if(x == el)
                cnt++;
            else
                cnt--;
        }
        int cnt1 = 0;
        for(int x : nums){
            if(x == el)
                cnt1++;
        }
        if (cnt1 > nums.size() / 2)
            return el;
        return -1;
    }
};