class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, minimizedmaxsum = INT_MIN;
        std::sort(nums.begin(), nums.end());     
        while(i<j){     // T.C of this loop is O(n/2) which simplifies to O(n)
            if(nums[i] + nums[j] > minimizedmaxsum){
                minimizedmaxsum = nums[i] + nums[j];
            }
            i++;
            j--;
        }
        return minimizedmaxsum;
    }
};


// Difficulties faced(if any): why even sort the array in the first place ? understanding "The maximum pair sum is minimized"; what is meant by optimally pairing up the elements ?
// T.C. =  O(nlogn) + O(n/2) = O(n log n)
// S.C. = O(1) 