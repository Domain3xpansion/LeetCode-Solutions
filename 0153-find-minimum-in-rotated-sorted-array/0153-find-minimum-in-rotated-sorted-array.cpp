class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, min = INT_MAX;
        while(low <= high){
            long mid = low + (high - low) / 2;
            if(nums[low] <= nums[mid]){
                if(nums[low] < min)
                    min = nums[low];
                    low = mid+1;
            }else{ 
                if(nums[mid] < min)                                     
                    min = nums[mid];
                high = mid-1;
            }
        }
        return min;
    }
};