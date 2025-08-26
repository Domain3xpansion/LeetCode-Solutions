class Solution {
public:
    double divandsum(vector<int>& nums, long mid){
        int n = nums.size();
        double s=0;
        for(int i=0; i<n; i++){
            s += ceil((double)nums[i]/(double)mid);
        }
        return s;
    }

    int smallestDivisor(vector<int>& nums, int threshold){
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            long mid = low + (high - low)/2;
            int summ = divandsum(nums, mid);
            if(summ <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};