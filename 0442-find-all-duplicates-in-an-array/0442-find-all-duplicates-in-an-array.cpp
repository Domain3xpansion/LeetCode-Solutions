class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*vector<int> emp;
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                if (emp.empty() || emp.back() != nums[i]) {
                    //emp.back() != nums[i] because there can be a case when the 2 elements 
                    //being compared are equal but that element is already pushed to the solution array due to prior 
                    //operations
                    emp.push_back(nums[i]);
                }
            }
        }
        return emp;
        */

        
        vector<int> emp;
        unordered_map<long, long> hm;
        for(int number : nums){
            hm[number]++;
        }
        for(const auto& pair : hm){
            if(pair.second > 1){
                emp.push_back(pair.first);
            }
        }
        return emp;
    }
};