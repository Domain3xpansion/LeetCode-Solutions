class Solution {
public:
    int maxProduct(vector<int>& nums){
        /*int prod, n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                prod = 1;
                for(int k=i; k<=j; k++){
                    prod = prod * nums[k];
                }
                maxi = max(maxi, prod);
            }  
        }
        return maxi;*/

        /*int prod, n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            prod = 1;
            for(int j=i; j<n; j++){
                prod = prod * nums[j];
                maxi = max(maxi, prod);
            }  
        }
        return maxi;*/

        int maxi = INT_MIN;
        int prefix = 1, suffix = 1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(prefix == 0)
                prefix = 1;
            if(suffix == 0)
                suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};