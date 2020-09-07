class Solution {
public:
    int search(vector<int>& nums, int target) {
        // We employ an algorithm similar to binary search. 
        int lo = 0, hi = nums.size() - 1;
        int mid = 0;
        
        while(lo < hi){
            int mid = (lo + hi) / 2;
            
            if(nums[mid] == target) return mid;
            
            // Here, we use bits manipulation for boolean statement 
            // if only one of these statement is true, lo becomes mid + 1. 
            // if two of these statements are true, lo becomes mid + 1. 
            // if all three of these statements are true, lo becomes mid + 1 
            
            // nums[0] > target 
            //  if 3 4 5 7 0 1 2, then target must be after 7
            //  if 7 1 2 3 4 5 6  the target is after after 7 
            //  if 1 2 3 4 5 6 7  then it is not possible 
            
            // nums[0] > nums[mid]
            // if 3 4 5 7 0 1 2, true if mid is after 7, false if it is before 7
            // if 1 2 3 4 5 6 7, never true 
            // if 7 1 2 3 4 5 6, always true 
            
            // target > nums[mid]
            // 1 2 3 4 5 6 7 
            // 3 4 5 6 7 1 2 
            // 7 1 2 3 4 5 6   
            if((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        
        //checks if lo is in bound and return lo if nums[lo] is target
        return lo < nums.size() && nums[lo] == target ? lo : -1;
    }
};




