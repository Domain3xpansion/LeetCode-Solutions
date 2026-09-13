class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int r = n, c = n, num = 1;
        int top = 0, bottom = r-1, left = 0, right = c-1;
        while(left <= right && top <= bottom){
            for(int i=left; i <= right; i++){
                mat[top][i] = num;
                num++;
            }
            top++;
            for(int j=top; j<=bottom; j++){
                mat[j][right] = num;
                num++;
            }
            right--;
            if(top <= bottom){  
                for(int i=right; i>=left; i--){
                    mat[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            if(left <= right){
                for(int j=bottom; j>=top; j--){
                    mat[j][left] = num;
                    num++;
                }
                left++;
            }
        }
        return mat;
    }
};