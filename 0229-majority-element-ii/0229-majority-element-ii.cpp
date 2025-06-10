class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*unordered_map<int, int> hashmap;
        vector<int> vec;
        int n = nums.size();
        int min = (n/3) + 1;
        for(int x : nums){
            hashmap[x]++;
            if(hashmap[x] == min)
                vec.push_back(x);
        }
        return vec;*/

        int cnt1 = 0, cnt2 = 0;
        int el1, el2;
        for(int x : nums){
            if(cnt1 == 0 && el2 != x){
                cnt1 = 1;
                el1 = x;
            }else if(cnt2 == 0 && el1 != x){
                cnt2 = 1;
                el2 = x;
            }else if(x == el1)
                cnt1++;
            else if(x == el2)
                cnt2++;
            else{
                cnt1--;
                cnt2--;    
            }
        }
        vector<int> res;
        cnt1 = 0, cnt2 = 0;
        for(int x : nums){
            if(x == el1)
                cnt1++;
            if(x == el2)
                cnt2++;
        }
        int major = (nums.size()/3) + 1;
        if(cnt1 >= major)
            res.push_back(el1);
        if(cnt2 >= major)
            res.push_back(el2);
        return res;
    }
};