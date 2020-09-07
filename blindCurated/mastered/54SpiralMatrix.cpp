class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return vector<int>(); 
        }
        
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.size();
        int colEnd = matrix[0].size(); 
        vector<int> ans; 
        
        while(rowStart < rowEnd && colStart < colEnd){
            for(int i = colStart; i < colEnd; ++i){
                //cout << matrix[rowStart][i] << endl; 
                ans.push_back(matrix[rowStart][i]);
            }
            
            //cout << "finish right" << endl;
            
            for(int i = rowStart + 1; i < rowEnd; ++i){
                //cout << matrix[i][colEnd - 1] << endl;
                ans.push_back(matrix[i][colEnd - 1]); 
            }
            
            //cout << "finish down" << endl;
            
            //Reasons for the if statements. Depending on row size is even or
            //  odd, etc, the last two loops may be skipped. 

            if(rowStart != rowEnd - 1){
                for(int i = colEnd - 2; i >= colStart; --i){
                    //cout << matrix[rowEnd - 1][i] << endl;
                    ans.push_back(matrix[rowEnd - 1][i]);
                }
            }
            
            //cout << "finish left" << endl;
            
            if(colStart != colEnd - 1){
                for(int i = rowEnd - 2; i > rowStart; --i){
                    //cout << matrix[i][colStart] << endl;
                    ans.push_back(matrix[i][colStart]);
                }
            }
            
            //cout << "finish up" << endl;
            
            ++colStart; 
            --colEnd;
            ++rowStart;
            --rowEnd; 
        }
        
        
        
        return ans;
        
    }
};
