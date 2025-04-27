class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*int lConsec = 0;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i], consec = 1;
            auto it = find(nums.begin(), nums.end(), num+1);
            while(it != nums.end()){
                consec++;
                num = num+1;
                it = find(nums.begin(), nums.end(), num + 1);
            }
            if(consec>lConsec)
                lConsec = consec;
        }
        return lConsec;
        */
        /*
        int small = INT_MIN, lConsec = 0, consec=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]-1 == small){
                consec++;
                small = nums[i];
            }else if(small != nums[i]){
                consec = 1;
                small = nums[i];
            }
            lConsec = max(lConsec, consec);
        }
        return lConsec;
        */
        if(nums.empty()) return 0;
        int n = nums.size(), consec, lConsec=0;
        unordered_set<int> us(nums.begin(), nums.end());
        for(auto num : us){
            if(us.find(num-1) == us.end()){
                consec = 1;
                int x = num;
                while(us.find(x+1) != us.end()){
                    consec++;
                    x++;
                }
                lConsec = max(lConsec, consec);
            } 
        }
        return lConsec;
    }
};