class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
		// reason why we use l + (r - l)/2 instead of (r - l) / 2:
		//   say we have r = 3, l = 2
        //   (r - l) / 2  = 1, which is not in the range of l to r
        //   l + (r - l) / 2 = 2, which is in the range of l to r.
        //   l + (r - l) / 2  will always lean towards l if r - l is even. 
        int m = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};


//O(n) time with O(1) space 
// class Solution {
//     public: 
//         int maxSubArray(vector<int>& nums){
//             if(nums.size() == 0) return 0;
            
//             int prevSum = nums[0], ans = nums[0];
            
//             for(int i = 1; i < nums.size(); ++i){
//                 if(prevSum > 0){
//                     prevSum += nums[i];
//                 }else{
//                     prevSum = nums[i];
//                 }
                
//                 ans = max(prevSum, ans);
//             }
            
//             return ans;
//         }
    
// };


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
