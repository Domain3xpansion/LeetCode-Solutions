class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Brute force
        /*int n = fruits.size(), maxlen = 0;
        for(int i=0; i<n; i++){
            unordered_set<int> us;
            for(int j=i; j<n; j++){
                us.insert(fruits[j]);
                if(us.size() > 2)
                    break;
                maxlen = max(maxlen, j-i+1);
            }
        }
        return maxlen;*/


        unordered_map<int, int> um;
        int i = 0, j = 0, n = fruits.size(), maxlen = 0;
        while(j < n){
            um[fruits[j]]++;
            if(um.size() > 2){
                while(um.size() > 2){
                    um[fruits[i]]--;
                    if(um[fruits[i]] == 0)
                        um.erase(fruits[i]);
                    i++;
                }
            }
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};