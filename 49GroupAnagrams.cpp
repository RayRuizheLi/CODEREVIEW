class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> set; 
        vector<vector<string>> ans; 
        int anCount = 0;
        int size = strs.size();
        for(int i = 0; i < size; ++i){
            string s = strs[i];
            sort(s.begin(), s.end());
            unordered_map<string, int>::iterator it = set.find(s);
            if(it == set.end()){
                ans.push_back({strs[i]});
                set[s] = anCount;
                ++anCount; 
            }else{
                // anCount is it->second
                // used to indicate the hash of the found key.
                ans[it->second].push_back(strs[i]);
            }
        }
        
        return ans;
        
    }
};
