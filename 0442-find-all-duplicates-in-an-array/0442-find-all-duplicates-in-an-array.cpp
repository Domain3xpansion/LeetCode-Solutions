class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*vector<int> emp;
        std::sort(nums.begin(), nums.end());     // Sorts in O(nlogn)
        for(int i=0; i<nums.size()-1; i++){      // T.C. for this loop: O(n).
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
        //  Overall T.C.: O(nlogn) + O(n) = O(nlogn)
        //  S.C.: O(n)
        */
        
        vector<int> emp;
        unordered_map<long, long> hm;
        for(int number : nums){      // T.C. for this loop: O(n)
            hm[number]++;
        }
        for(const auto& pair : hm){
            if(pair.second > 1){    // If there are m unique elements, this loop runs in O(m)
                emp.push_back(pair.first);    //Since m can be at most n,  
            }                       // the T.C. for this loop: O(m), which can be up to O(n)
        }
        return emp;
        //   Overall T.C.: O(n) + O(m) = O(n)
    }
};