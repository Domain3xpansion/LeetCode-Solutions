class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*unordered_map<int, int> hashmap;
        int n = nums.size();
        int min = (n/2) + 1;
        for(int x : nums){
            hashmap[x]++;
            if(hashmap[x] == min)
                return x;
        }
        return -1;*/
        int cnt = 0;
        int el;
        for(int x : nums){
            if(cnt == 0){
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
        if(cnt1 > nums.size() / 2)
            return el;
        return -1;
    }
};