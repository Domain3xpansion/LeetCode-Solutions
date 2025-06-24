class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res;
        unordered_set<int> us;
        for(int i=0; i<n; i++){
            us.insert(stoi(nums[i], 0, 2));
        }
        for(int i=0; i<pow(2, n); i++){
            if(us.find(i) == us.end()){
                res = bitset<16>(i).to_string();
                return res.substr(16-n, n);
            }
        }
        return "";
    }
};