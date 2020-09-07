class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> maze(m, vector<int>(n, 0)); 
        
        for(int i = 1; i <= m; ++i){
            maze[i - 1][0] = 1; 
        }
        
        for(int i = 1; i <= n; ++i){
            maze[0][i - 1] = 1;
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                maze[i][j] = maze[i][j - 1] + maze[i - 1][j];
            }
        }
        
        return maze[m - 1][n - 1];    
    }
};
