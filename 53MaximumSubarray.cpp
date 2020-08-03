class Solution {
    public: 
        int maxSubArray(vector<int>& nums){
            if(nums.size() == 0) return 0;
            
            int prevSum = nums[0], ans = nums[0];
            
            for(int i = 1; i < nums.size(); ++i){
                if(prevSum > 0){
                    prevSum += nums[i];
                }else{
                    prevSum = nums[i];
                }
                
                ans = max(prevSum, ans);
            }
            
            return ans;
        }
    
};


//O(n) solution, waste of space 
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if(nums.size() == 0) return 0; 
        
//         vector<int> dp(nums.size(), 0); 
//         dp[0] = nums[0];
//         int num = dp[0];
            
//         for(int i = 1; i < nums.size(); ++i){
//             if(dp[i - 1] > 0){
//                 dp[i] = dp[i - 1] + nums[i];
//             }else{
             
//                 dp[i] = nums[i];
//             }
            
//             num = max(num, dp[i]);
//         }
        
//         return num; 
        
//     }
// };
