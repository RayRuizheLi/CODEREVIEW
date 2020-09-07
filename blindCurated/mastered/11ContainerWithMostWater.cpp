class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxarea = 0, l = 0, r = height.size() - 1; 
        while(l < r){
            // area is limited by the shorter height.
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            
            // move the pointer to shorter height in ward. 
            if(height[l] < height[r]) l++;
            else r--; 
        }
        
        return maxarea; 
    }
};
