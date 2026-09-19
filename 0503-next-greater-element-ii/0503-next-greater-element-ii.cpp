class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=0; i<n; i++){
            bool found = false;  
            for(int j=i+1; j<=i+n-1; j++){ 
                int index = j%n;
                if(nums[index] > nums[i]){
                    res.push_back(nums[index]);
                    found = true;
                    break;
                }
            }
            if(!found)
                res.push_back(-1);
        }
        return res;
    }
};