class Solution {
public:
    vector<vector<int>>merge(vector<vector<int>>& intervals){
        
        if(intervals.empty()) return {};
        
        
        sort(intervals.begin(), intervals.end(), [] (const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0];
        });
        
        
        vector<vector<int>> res; 
        int startC = intervals[0][0];
        int endC = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); ++i){
            int startN = intervals[i][0];
            int endN = intervals[i][1];
            
            if(startC <= startN && endC <= endN && endC >= startN){
                endC = endN; 
            }else if(startC <= startN && endC <= startN){
                res.push_back({startC, endC});
                startC = startN; 
                endC = endN; 
            }
        }
        
        res.push_back({startC, endC});
            
        return res;          
    }
};
