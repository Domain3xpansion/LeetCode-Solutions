class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int fmax = LONG_MIN;
        long int smax = LONG_MIN;
        long int tmax = LONG_MIN;
        
        for (int num : nums) {
            if (num == fmax || num == smax || num == tmax) {
                continue; 
            }
            if (num > fmax) {
                tmax = smax;
                smax = fmax;
                fmax = num;
            } else if (num > smax) {
                tmax = smax;
                smax = num;
            } else if (num > tmax) {
                tmax = num;
            }
        }
        return (tmax == LONG_MIN) ? fmax : tmax;
    }
};
