class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        int top = 0, bottom = r-1, left = 0, right = c-1;
        vector<int> res;
        while(left <= right && top <= bottom){
            for(int i=left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int j=top; j<=bottom; j++){
                res.push_back(matrix[j][right]);
            }
            right--;
            if(top <= bottom){
                for(int i=right; i>=left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                for(int j=bottom; j>=top; j--){
                    res.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return res;
    }
};