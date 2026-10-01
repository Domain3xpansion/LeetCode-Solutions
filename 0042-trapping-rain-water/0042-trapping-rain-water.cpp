class Solution {
public:
    int trap(vector<int>& height) {
        /* brute force
        TC = O(n) + O(n) + O(n) = O(3n) = O(n)
        SC = O(n) + O(n) = O(2n) = O(n)*/
        int n = height.size();
        int water = 0;
        vector<int> prefixMax(n), suffixMax(n);
        prefixMax[0] = height[0];
        suffixMax[n-1] = height[n-1];
        for(int i=1; i<n; i++){
            prefixMax[i] = max(height[i], prefixMax[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(height[i], suffixMax[i+1]);
        }
        for(int i=0;i<n;i++){
            if(height[i] < prefixMax[i] && height[i] < suffixMax[i])
                water += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return water;
    }
};