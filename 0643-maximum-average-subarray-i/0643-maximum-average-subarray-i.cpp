class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Brute force
        /*int n = nums.size();
        double maxAvg = -DBL_MAX;
        for(int i=0; i<=n-k; i++){
            for(int j=i+k-1; j<n; j++){
                if(j-i+1 == k){
                    int sum = accumulate(nums.begin()+i, nums.begin()+j+1, 0);
                    double avg = (double)sum/k;
                    maxAvg = max(maxAvg, avg);
                }
            }
        }
        return maxAvg;*/

        int n = nums.size();
        int sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        int maxSum = sum;
        for(int i=k; i<n; i++){
            sum += nums[i];
            sum -= nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }
};