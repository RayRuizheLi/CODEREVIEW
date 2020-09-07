class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matSize = matrix.size();
        
        if(matSize < 2) return;
        
        int len = matSize - 1; 
        
		// / 2 for i so we stop swapping at the middle. 
        for(int i = 0; i < matSize / 2; ++i){
            // len - i because each inner circle is smaller than the previous circle. 
            for(int j = i; j < len - i; ++j){
                swap(matrix[i][j], matrix[j][len - i]);
                swap(matrix[i][j], matrix[len - i][len - j]);
                swap(matrix[i][j], matrix[len - j][i]);
            }
        }
        
    }
};
