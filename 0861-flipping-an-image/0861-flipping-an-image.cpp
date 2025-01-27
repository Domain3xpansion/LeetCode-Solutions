class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            std::reverse(row.begin(), row.end());
        }
        for (int i=0; i<image.size(); i++){
            for(int j=0; j<image[0].size(); j++){
                image[i][j] = image[i][j] ^ 1;
            }
        }
        return image; 
    }
};