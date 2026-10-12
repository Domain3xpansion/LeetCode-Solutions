class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute force
        /*int n = nums.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            int prod = 1;
            for(int j=0; j<n; j++){
                if(i!=j)
                    prod *= nums[j];
            }
            res[i] = prod;
        }
        return res;*/

        int n = nums.size();
        vector<int> res(n);
        int totalprod = 1, zeroCount = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0)
                zeroCount++;
            else
                totalprod *= nums[i];
        }
        for(int i=0; i<n; i++){
            if(zeroCount>1){           
                res[i] = 0;
            }
            else if(zeroCount == 1){           
                if(nums[i] == 0)                
                    res[i] = totalprod;        
                else
                    res[i] = 0;
            }
            else
                res[i] = totalprod / nums[i];
        }
        return res;
    }
};