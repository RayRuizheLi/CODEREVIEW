class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) return 0; 
        
        int dp1 = 1; 
        int dp2 = 1; 
        
        for(int i = 2; i <= n; ++i){
            int tmp = dp2; 
            dp2 = dp1 + dp2;
            dp1 = tmp; 
        }
        
        return dp2; 
    }
};
