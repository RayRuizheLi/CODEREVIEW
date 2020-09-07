class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> pos; 
        
        if(s.size() == 0) return 0; 
        
        //st stores position right after the last repeating string
        //  ie where the new string starts
        int max_len = 1, start = 0, n = s.size();
        
        // instead of using sliding window, we calculate the difference between i and last recorded i for the repeated character. 
        
        for(int i = 0; i < n; ++i){
            char c = s[i];
            
            //if c exists in pos, and the position c last occurred is
            //  after the start of the current string.
            // Prevents ....c....start......c... from being counted as repeat.
            if(pos.count(c) && start <= pos[c]){
                int curr_len = i - start;
                max_len = max(curr_len, max_len);
                start = pos[c] + 1;
            }
            
            pos[c] = i;
        }
        
        //n - st is needed for the case that there are no repeating character.
        return max(max_len, (n - st));
    }
    
};

