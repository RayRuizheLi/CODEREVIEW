class Solution {
public:
    // binary search O(nlogn)
    int lengthOfLIS(vector<int>& nums) {        
        if(nums.size() == 0) return 0;
    // input: [0, 8, 4, 12, 2]
    // dp: [0]
    // dp: [0, 8]
    // dp: [0, 4]
    // dp: [0, 4, 12]
    // dp: [0 , 2, 12
    // stores an array of increasing numbers 
        vector<int> dp;
        
        for(int num : nums){
            int pos = binarySearch(dp, num);
            if (pos >= dp.size()) {
                dp.push_back(num);
            } else {
                dp[pos] = num;
            }
        }
        
        return dp.size();
    }
    
private: 
    int binarySearch(vector<int>& dp, int num){
        int left = 0; 
        int right = dp.size() - 1;
        int mid = 0;
        
        while(left <= right){
            mid = (left + right) / 2; 
            if (dp[mid] == num) {
                return mid;
            } else if (num < dp[mid]) {
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        
        return left;
    }

};

