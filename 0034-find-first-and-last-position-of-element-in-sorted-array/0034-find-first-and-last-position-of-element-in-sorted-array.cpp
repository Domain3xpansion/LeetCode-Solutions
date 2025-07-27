class Solution {
public:
/*
    int lowerbound(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    int upperbound(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerbound(nums, target);
        if(lb == nums.size() || nums[lb] != target)
            return {-1, -1};
        return {lb, upperbound(nums, target) - 1};
    }
    */

    int firstocc(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }

    int lastocc(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstocc(nums, target);
        if(first == -1)
            return {-1, -1};
        int last = lastocc(nums, target);
        return {first, last};
    }
};