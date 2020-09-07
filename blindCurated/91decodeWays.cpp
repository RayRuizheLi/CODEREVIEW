class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        
        dp[0] = 1;
        
        if (s[0] > '0') {
            dp[1] = 1;
        }
        
        for (int i = 2; i <= s.size(); ++i) {
            // If it isn't 0, there are at least the previous # of ways
            if (s[i-1] > '0') {
                dp[i] = dp[i-1];
            }
                
            // Now we check for additional ways
            // If the past 2 numbers are [1, 26], then 
            // there are dp[i-2] more ways
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[s.size()];
    }
};
