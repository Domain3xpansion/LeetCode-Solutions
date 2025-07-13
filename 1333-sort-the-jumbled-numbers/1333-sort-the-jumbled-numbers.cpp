class Solution {
public:
    string conv(string &s, vector<int>& mapping){
        string res = "";
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            int x = ch - '0';
            res += to_string(mapping[x]);
        }
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        /*vector<pair<int, int>> vec;
        vector<int> op;
        int n = nums.size();
        for(int i=0; i<n; i++){
            string s = to_string(nums[i]);
            string s_equiv_num = conv(s, mapping);
            int equiv_num = stoi(s_equiv_num);
            vec.push_back({equiv_num, i});
        }
        sort(vec.begin(), vec.end());
        for(auto i: vec){
            int k = i.second;
            op.push_back(nums[k]);
        }
        return op;*/

        vector<pair<int, int>> vec;
        vector<int> op;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int copy = nums[i];
            int equiv = 0, placeval = 1;
            if(copy == 0)
                equiv = mapping[0];
            else{
                while(copy>0){
                    int rem = copy % 10;
                    equiv += placeval * mapping[rem];
                    copy /= 10;
                    placeval *= 10;
                }
            }
            vec.push_back({equiv, i});
        }
        sort(vec.begin(), vec.end());
        for(auto i: vec){
            op.push_back(nums[i.second]);
        }
        return op;
    }
};