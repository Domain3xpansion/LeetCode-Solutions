class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        for(auto& val:answers){
            mp[val]++;
        }
        int total = 0;
        for(auto& it:mp){
            int groupsize = it.first + 1;
            int noofgroups = ceil(double(it.second)/groupsize);
            total += groupsize * noofgroups;
        }
        return total;
    }
};