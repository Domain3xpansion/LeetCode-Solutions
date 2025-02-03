class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> visit;
        while(n!=1){     
            if(visit.find(n) != visit.end()){
                return false;
            }
            visit.insert(n);
            int sum = 0;
            while(n>0){
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};