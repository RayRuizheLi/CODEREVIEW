class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; 
        
        
        // create a map of (compliment, index) pair
        for(int i = 0; i < nums.size(); ++i){
            m[target - nums[i]] = i;
        }
        
        // search if compliment exists and the complement is not self. 
        for(int i = 0; i < nums.size(); ++i){
            if(m.count(nums[i]) > 0 && m[nums[i]] != i){
                return {m[nums[i]], i};
            }
        }
        
        return {};
    }
};
