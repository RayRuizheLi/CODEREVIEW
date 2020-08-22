class Solution {
public:
    string minWindow(string s, string t) {
        // Really compressed version for c++ 
        // Assumes 128 ASCII characters
        vector<int> hist(128, 0);
        
        // Count the amount of characters in t 
        for(char c :  t) hist[c]++; 
        
        // Instead of counting unique character, we are just gonna keep
        //   track of the total amount of characters needed. 
        int remaining = t.length(); 
        
        int l = 0, r = 0, minStart = 0, minLen = -1; 
        while(r < s.length()){
            if(--hist[s[r++]] >= 0) --remaining;
            while(remaining == 0){
                
                //cout << "r: " << r << ", l: " << l << endl; 
                if(r - l < minLen || minLen == -1){
                    minLen = r - l;
                    minStart = l;
                }
                
                if(++hist[s[l++]] > 0) ++remaining;
            }
        }
        
        return minLen == -1 ? "" : s.substr(minStart, minLen); 
    }
};


// // Supposed to be faster, but in reallity slower. Might be because pair is just slow. 
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         // Really compressed version for c++ 
//         // Assumes 128 ASCII characters
//         vector<int> hist(128, 0);
        
//         // Count the amount of characters in t 
//         for(char c :  t) hist[c]++; 
        
//         // Instead of counting unique character, we are just gonna keep
//         //   track of the total amount of characters needed. 
//         int remaining = t.length(); 
        
//         vector<pair<char, int>> filtS; 
        
//         for(int i = 0; i < s.size(); ++i){
//             if(hist[s[i]] > 0) filtS.push_back(make_pair(s[i], i));
//         }
        
//         int l = 0, r = 0, minStart = 0, minLen = -1; 
        
//         while(r < filtS.size()){
            
//             //cout << "filtS[r].first: " << filtS[r].first << endl; 
//             //cout << "hist[filtS[r].first]: " << hist[filtS[r].first] << endl;
//             if(--hist[filtS[r].first] >= 0){
//                 //cout << "hit" << endl; 
                
//                 --remaining;
//             } 
            
//             while(remaining == 0){
                 
//                 int start = filtS[l].second;
//                 int end = filtS[r].second; 
                
//                 //cout << "start: " << start << ", end: " << end << endl;
                
//                 if(end - start + 1 < minLen || minLen == -1){
//                     //cout << " small found, start: " << start << ", end: " << end << endl;
//                     minLen = end - start + 1;
//                     minStart = start;
//                 }
                
//                 if(++hist[filtS[l++].first] > 0) ++remaining;
//             }
            
//             ++r;
//         }
        
//         return minLen == -1 ? "" : s.substr(minStart, minLen); 
//     }
// };

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if(s.length() == 0 || t.length() == 0) {
//             return "";
//         }
        
//         unordered_map<char, int> dictT;
        
//         for(int i = 0; i < t.size(); ++i){
//             if(dictT.count(t[i]) <= 0) dictT[t[i]] = 1;
//             else ++dictT[t[i]];
//         }
        
//         int required = dictT.size();
        
//         // Filter all the characters from s into a new list along with their index. 
//         // The filtering criteria is that the character should be present in t
//         vector<pair<int, char>> filteredS; 
        
//         for(int i = 0; i < s.size(); ++i){
//             char c = s[i];
//             if(dictT.count(c) > 0){
//                 filteredS.push_back(make_pair(i, c));
//             } 
//         }
        
//         int l = 0, r = 0, formed = 0; 
//         unordered_map<char, int> windowCounts; 
//         vector<int> ans = {-1, 0, 0};
        
//         // Look for the characters only in the filtered list instead of the entire s. 
//         // This helps to reduce our search. 
//         // Hence, we follow the sliding window approach on as small list. 
//         while(r < filteredS.size()) {
//             char c = filteredS[r].second;

//             if(windowCounts.count(c) <= 0) windowCounts[c] = 1;
//             else ++windowCounts[c];

//             if(dictT.count(c) > 0 && windowCounts[c] == dictT[c]){
//                 ++formed;
//             } 
            
//             while(l <= r && formed == required){
//                 c = filteredS[l].second; 
                
//                 // Save the smallest window until now. 
//                 int end = filteredS[r].first; 
//                 int start = filteredS[l].first; 
                
//                 if (ans[0] == -1 || end - start + 1 < ans[0]) {
//                   ans[0] = end - start + 1;
//                   ans[1] = start;
//                   ans[2] = end;
//                 }
                
//                 --windowCounts[c];
                
//                 if(dictT.count(c) > 0 && windowCounts[c] < dictT[c]){
//                     formed--; 
//                 }
                
//                 ++l; 
//             }
            
//             ++r;
//         }
        
//         return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
        
//     }
// };

