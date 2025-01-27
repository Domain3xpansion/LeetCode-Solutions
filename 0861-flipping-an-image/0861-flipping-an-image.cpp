class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {         //will give error if you write for(auto row: image) 
            std::reverse(row.begin(), row.end());   //reversing each row of the 2D matrix
        }
        for (int i=0; i<image.size(); i++){
            for(int j=0; j<image[0].size(); j++){   
                image[i][j] = image[i][j] ^ 1;     //accessing each element of the 2D matrix
            }
        }
        return image; 
    }
};