class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
        for(int i=0; i<bank.size(); i++){
            int count = 0;
            for(char ch: bank[i]){
                if(ch == '1')
                    count++;
            }
            res += (count * prev);
            if(count != 0)
                prev = count;
        }
        return res;
    }
};