class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2 != 0)
            return {};
        unordered_map<int, int> um;
        vector<int> original;
        sort(changed.begin(), changed.end());
        for(auto &x : changed){
            um[x]++;
        }
        for(int &x : changed){
            int twice = 2 * x;
            if(um[x] == 0)
                continue;
            if(um.find(twice) == um.end() || um[twice] == 0)
                return {};
            original.push_back(x);
            um[x]--;
            um[twice]--;
        }
        return original;
    }
};