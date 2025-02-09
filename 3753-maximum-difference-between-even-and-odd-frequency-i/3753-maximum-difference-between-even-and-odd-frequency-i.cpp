class Solution {
public:
    int maxDifference(string s) {
        int evenf = INT_MAX, oddf = INT_MIN;
        map<char, int> freqMap;
        for(char c : s){ 
            freqMap[c]++; 
        }
        for(const auto pair : freqMap){
            if(pair.second % 2 == 0){
                if(pair.second < evenf){
                    evenf = pair.second;
                }
            }else{
                if(pair.second > oddf){
                    oddf = pair.second;
                }
            }
        }
        return oddf - evenf;
    }
};

//T.C. = O(n log k)
//S.C.= O(k)