class Solution {
public:
    bool judgeSquareSum(int c) {
       /*unordered_map<int, bool> hashtable;
        for(int i=0; i<sqrt(c); i++){
            int y = sqrt(c - i*i);
            if(hashtable.find(y) != hashtable.end())
                return true;
            else
                hashtable[i] = true;
        }
        return false; 
        */
        long left = 0;
        long right = static_cast<int>(sqrt(c));
        while(left <= right){
            long total = left * left + right * right;
            if(total > c)
                right--;
            else if (total < c)
                left++;
            else
                return true;
        }
        return false;
    }
};