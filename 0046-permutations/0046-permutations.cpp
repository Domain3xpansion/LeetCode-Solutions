class Solution {
public:
    /*void permutations(vector<int> vec, vector<int> &freq, vector<vector<int>> &ans, vector<int> &ds){
        if(ds.size() == vec.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<vec.size(); i++){
            if(!freq[i]){
                ds.push_back(vec[i]);
                freq[i] = 1;
                permutations(vec, freq, ans, ds);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }*/

    
    void permutationsswap(int index, vector<int> vec, vector<vector<int>> &ans2){
        if(index == vec.size()){
            ans2.push_back(vec);
            return;
        }
        for(int i=index; i<vec.size(); i++){
            swap(vec[index], vec[i]);
            permutationsswap(index+1, vec, ans2);
            swap(vec[index], vec[i]);       
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        /*
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> freq(n, 0);
        permutations(nums, freq, ans, ds);
        return ans;*/
        vector<vector<int>> ans2;
        permutationsswap(0, nums, ans2);
        return ans2;
    }
};