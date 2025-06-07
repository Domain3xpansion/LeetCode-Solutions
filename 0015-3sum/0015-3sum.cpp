class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /* Brute force
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> vec = {nums[i], nums[j], nums[k]};
                        sort(vec.begin(), vec.end());
                        s.insert(vec);
                    }
                }
            }
        }
        vector<vector<int>> res(s.begin(), s.end());
        return res;*/

        /* Better solution
        int n = nums.size();
        set<vector<int>> unique_triplet;
        for(int i=0;i<n;i++){
            set<int> s;
            for(int j=i+1; j<n; j++){
                int sum = -(nums[i] + nums[j]);
                if(s.find(sum) != s.end()){
                    vector<int> vec = {nums[i], nums[j], sum};
                    sort(vec.begin(), vec.end());
                    unique_triplet.insert(vec);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> res(unique_triplet.begin(), unique_triplet.end());
        return res;*/
        
        // Optimal solution
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0)
                    j++;
                else if(sum>0)
                    k--;
                else{
                    vector<int> vec = {nums[i], nums[j], nums[k]};
                    res.push_back(vec);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1])
                        j++;
                    while(j<k && nums[k] == nums[k+1])
                        k--;
                }
            }
        
        }
        return res;
    }
};