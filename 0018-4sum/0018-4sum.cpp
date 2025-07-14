class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*int n = nums.size();
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
        return res;*/

        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());         // O(n log n)
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum<target)
                        k++;
                    else if(sum>target)
                        l--;
                    else{
                        vector<int> vec = {nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(vec);
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1])
                            k++;
                        while(k<l && nums[l] == nums[l+1])
                            l--;
                    }
                }
            }
        }
        return res;
    }
};