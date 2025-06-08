class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*int n = nums.size(), sum, count=0;
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(k == sum) count++; 
            }
        }
        return count;*/
        unordered_map<int, int> um;
        um[0] = 1;
        int presum = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            presum += nums[i];
            int remove = presum - k;
            count += um[remove];
            um[presum] += 1;
        }
        return count;
    }
};