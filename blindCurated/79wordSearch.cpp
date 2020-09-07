class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size();
        
        if(rowSize == 0){
            return false; 
        }
        
        int colSize = board[0].size();
        bool ans = false; 
        
        // Handling the special case of only one item 
        if(rowSize == 1 && colSize == 1 && word.size() == 1){
            ans = board[0][0] == word[0];
        }  
        
        for(int row = 0; row < rowSize; ++row){
            for(int col = 0; col < colSize; ++col){
                if(board[row][col] == word[0]){
                    findWord(board, word, 0, row, col, ans);
                    if(ans){
                        break;
                    }
                }
            }
            if(ans){
                break;
            }
        }
        
        return ans; 
        
    }
private: 
    // First optimization: use l reference for word
    void findWord(vector<vector<char>>& board, string& word, int curInd, int row, int col, bool& ans){
        if(curInd >= word.size()){
            ans = true; 
        }
        
        if(board[row][col] == word[curInd]){
            //second optimization: 
            //Instead of copying the board everytime, we are just going to change the
            // signal variable back lmao. 
            char tmp = board[row][col];
            board[row][col] = '1';
            
            //try go up
            if(row - 1 >= 0){
                findWord(board, word, curInd + 1, row - 1, col, ans);
            }

            //try go down
            if(ans != true && row + 1 < board.size()){
                findWord(board, word, curInd + 1, row + 1, col, ans);
            }

            //try go right 
            if(ans != true && col + 1 < board[0].size()){
                findWord(board, word, curInd + 1, row, col + 1, ans);
            }

            //try go left 
            if(ans != true && col - 1 >= 0){
                findWord(board, word, curInd + 1, row, col - 1, ans);
            }
            
            board[row][col] = tmp;
        }
    }
};
