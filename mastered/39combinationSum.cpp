class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> path; 
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, res, path);
        
        return res;
    }
    
private:
    void dfs(const vector<int>& candidates, int target, int idx, vector<vector<int>>& res, vector<int>& path){
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = idx; i < candidates.size(); ++i){
            if(candidates[i] > target) return; 
            
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, res, path);
            path.pop_back();
        }
    }
};

//pop_back() ensures that all of the newly inserted element is removed. 
//i: 0
//path before dfs: 2 
//i: 0
//path before dfs: 2 2 
//i: 0
//path before dfs: 2 2 2 
//path after dfs: 2 2 2 
//path after pop: 2 2 
//
//i: 1
//path before dfs: 2 2 3 
//path after dfs: 2 2 3 
//path after pop: 2 2 
//
//path after dfs: 2 2 
//path after pop: 2 
//
//i: 1
//path before dfs: 2 3 
//path after dfs: 2 3 
//path after pop: 2 
//
//path after dfs: 2 
//path after pop: 
//
//i: 1
//path before dfs: 3 
//i: 1
//path before dfs: 3 3 
//path after dfs: 3 3 
//path after pop: 3 
//
//path after dfs: 3 
//path after pop: 
//
//i: 2
//path before dfs: 6 
//path after dfs: 6 
//path after pop: 
//
//i: 3
//path before dfs: 7 
//path after dfs: 7 
//path after pop: 
