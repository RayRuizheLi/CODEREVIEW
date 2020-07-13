class Solution {
public:
    string longestPalindrome(string s) {   
        
        if(s.size() < 2) return s; 
        
        int n = s.size(), st = 0, len = 0;
        
        for(int i = 0; i < n;){

            //(n - 1) - i + 1 = n - i
            // checks if there are enough chars in the rest of the array to break the record.  
            if(n - i < len / 2) break;
            
            int l = i, r = i;
            
            // This covers cases of rrr or rr or rrrrr
            while(r < n - 1 && s[r + 1] == s[r]) ++r; 
            
            // sets the next center to be after r
            i = r + 1; 
            
            while(r < n - 1 && l > 0 && s[r + 1] == s[l - 1]){
                ++r;
                --l;
            }
            
            if(len < r - l + 1){
                len = r - l + 1; 
                st = l; 
            }
        }
            
        return s.substr(st, len); 
    }
};
