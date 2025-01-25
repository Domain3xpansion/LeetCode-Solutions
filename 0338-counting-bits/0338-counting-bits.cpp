class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec(n + 1, 0);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                vec[i] = vec[i >> 1];
            } else {
                vec[i] = vec[i - 1] + 1;
            }
        }
        return vec;
    }
};