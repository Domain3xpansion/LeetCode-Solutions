class Solution {
public:
    int summation(vector<int>& vec){
        int summ = 0;
        for(int x : vec){
            summ += x;
        }
        return summ;
    }
    int splitarr(vector<int>& nums, int mid){
        int summ = 0, noofsubarr = 1;
        for(int i=0; i<nums.size(); i++){
            if(summ + nums[i]>mid){
                noofsubarr++;
                summ = 0;
            }
            summ += nums[i];
        }
        return noofsubarr;
    }
    int splitArray(vector<int>& nums, int k){
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end()), high = summation(nums);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(splitarr(nums, mid) > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};