class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        
        // create a filtered f_s so we only consider characters in s 
        //   that is also in t. 
        vector<int> counts(128, 0);
        
        for(char c : t){
            ++counts[c];
        }
        
        //We keep expanding the window by moving the right pointer. 
        //When the window has all the desired characters, we contract
        // (if possible) and save the smallest window till now.
        
        int left = 0; 
        int right = 0; 
        int len = INT_MAX;
        int start = -1;
        int remain = t.size();
        
        
        // implementation of sliding window 
        while(right < s.size()){
            // remaining characters in T
            remain -= counts[s[right]] > 0;
            --counts[s[right]];
            ++right;
            while(remain == 0){
                // 
                if(len > right - left){
                    len = right - left; 
                    start = left;
                }
                //increment remain by 1
                //  move left until it passes an character in T.
                remain += counts[s[left]] == 0; 
                ++counts[s[left]];
                ++left; 
            }
        }
        
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
