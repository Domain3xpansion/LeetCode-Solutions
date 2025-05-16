class Solution {
public:
    //Approach 1 - using the frequency of all numbers present in the given vector(using unordered_map)
    /*void permuteUniquehelper(vector<int>& ds, unordered_map<int, int> &um, vector<vector<int>> &result, int n){
        if(ds.size() == n) { 
            result.push_back(ds);   //O(n) time
            return;
        }
        for(auto& [num, count] : um){
            if(count == 0)
                continue;
            ds.push_back(num);
            um[num]--;

            permuteUniquehelper(ds, um, result, n);

            ds.pop_back();
            um[num]++;
        }
    }*/

    void permutations2swap(int index, vector<int> vec, vector<vector<int>> &ans2){
    if(index == vec.size()){
        ans2.push_back(vec);
        return;
    }
    unordered_set<int> us;
    for(int i=index; i<vec.size(); i++){ 
        if(us.find(vec[i]) != us.end()) continue;

        us.insert(vec[i]);
        swap(vec[index], vec[i]);

        permutations2swap(index+1, vec, ans2);

        swap(vec[index], vec[i]);        
    }
}
    
    vector<vector<int>> permuteUnique(vector<int>& nums){
        /*
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;   // will store the each permutation
        unordered_map<int, int> um;    // to store frequency of every number present in nums vector
        for(auto& num : nums){     // count the occurrences of each number
            um[num]++;
        }
        permuteUniquehelper(temp, um, result, n);
        return result;*/
        vector<vector<int>> ans2;
        permutations2swap(0, nums, ans2);
        return ans2;
    }
};