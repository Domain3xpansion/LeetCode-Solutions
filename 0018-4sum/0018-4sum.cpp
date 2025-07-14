class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> unique_quad;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                set<long long> s;
                for(int k=j+1; k<n; k++){
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    long long fourth =  target - sum;
                    if(s.find(fourth) != s.end()){               
                        vector<int> vec = {nums[i], nums[j], nums[k], (int)fourth};      
                        sort(vec.begin(), vec.end());                 
                        unique_quad.insert(vec);
                    }             
                    s.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> res(unique_quad.begin(), unique_quad.end());
        return res;
    }
};