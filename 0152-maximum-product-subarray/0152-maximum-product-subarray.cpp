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

        int prod, n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            prod = 1;
            for(int j=i; j<n; j++){
                prod = prod * nums[j];
                maxi = max(maxi, prod);
            }  
        }
        return maxi;
    }
};