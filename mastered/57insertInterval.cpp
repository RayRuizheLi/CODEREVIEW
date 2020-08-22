class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& nw) {
        vector<vector<int>> ans; 
        
        int nwS = nw[0];
        int nwE = nw[1];
        
        for(int i = 0; i < intervals.size(); ++i){
            
            int sC = intervals[i][0];
            int eC = intervals[i][1];
            
            if(sC < nwS && eC < nwS){
                ans.push_back({sC, eC});
            }else if(sC <= nwS && eC >= nwS && eC <= nwE){
                nwS = sC;
            }else if(sC >= nwS && sC <= nwE && eC >= nwE){
                nwE = eC; 
            }else if(sC <= nwS && eC >= nwS && eC >= nwE){
                nwS = sC; 
                nwE = eC;
            }else if(sC >= nwS && sC >= nwE){
                ans.push_back({nwS, nwE});
                nwS = sC;
                nwE = eC; 
            }
        }
        
        ans.push_back({nwS, nwE});
        
        return ans; 
    }
};

