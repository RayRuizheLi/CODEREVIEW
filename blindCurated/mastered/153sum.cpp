class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {}; 
        
        int n = nums.size(); 
        
        sort(nums.begin(), nums.end()); 
        
        vector<vector<int>> ans; 
        
        for(int i = 0; i < n;){
            // if current is positive, it is impossible to find a match since 
            // start and end will also be positives. 
            if(nums[i] > 0) break; 
            
            // -4, -1, -1, 0, 1, 2
            //  |i  |start       |end 
            
            int start = i + 1, end = n - 1, curr = nums[i], sum = 0; 
            
            while(start < end){
                sum = nums[start] + nums[end] + curr; 
                
                //sum is too big, we move end pointer towards <- left
                if(sum > 0) --end; 
                //sum is too small, we move pointer to right -> 
                else if(sum < 0) ++start; 
                //sum equals to zero, we found a match.  
                else{
                    //add the found touple to the answer. 
                    ans.push_back({curr, nums[start], nums[end]});
                    //we move both start and end here because there is no way we have a 
                    //match with the the same start or end. If there is, it would be a 
                    //dublicate. 
                    ++start; 
                    --end;
                    //If there are dupilcates of nums[start], we move all the way to 
                    //the last duplicate. 
                    while(start < end && (nums[start] == nums[start - 1])) ++start;
                    //same as above. 
                    while(start < end && (nums[end] == nums[end + 1])) --end; 
                }
            }
            
            //increment curr. 
            i++;
            
            //if there are duplicates of curr, we move all the way to the last 
            //duplicate of curr. 
            while(i < n && nums[i] == nums[i - 1]) ++i; 
        }
 
        return ans; 
    }
};
