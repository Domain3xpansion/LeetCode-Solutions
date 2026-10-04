class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), rsum = 0;
        int j = n-1;
        int lsum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int maxSum = lsum;
        for(int i=k-1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[j];
            j--;
            maxSum = max(maxSum, lsum + rsum);
        }
        return maxSum;
    }
};