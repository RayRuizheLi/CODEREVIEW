//Manacher's Algorithm
class Solution {
public:
    int countSubstrings(string s) {
        // Variable to store the modified array 
        // size of t will be at least 2 * size s + 1
        vector<char>t; 
        t.push_back('#'); 
        
        //Add # besides every character in the string 
        for(char c : s){
            t.push_back(c);
            t.push_back('#');
        }
        
        //p stores the radius of palindrom center at index i of t. 
        vector<int> p(t.size()); // initialize all to 0
        
        //next is implementation of Manacher's Algorithm. 
        //initialize the right most bound rb and the center of right most bound.
        int c = 0; 
        int rb = -1; 
        int rad = 0;
        
        for(int i = 0; i < t.size(); ++i){
            if(i <= rb){
                // If i is within right bound, radius is min of(radius of index reflection at center or distance from i to right bound)
                rad = min(p[2 * c - i], rb - i); 
            }else{
                rad = 0; //reset radius to calculate it later. 
            }
            
            //increment radius while palindrome does not exceeds the two ends of string s
            //  and the two letters next to the two ends matches. 
            while(i + rad + 1 < t.size() && i - rad - 1 >= 0 && t[i + rad + 1] == t[i - rad - 1]){
                ++rad; 
            }
            
            p[i] = rad;
            
            // if the new palindrome's right bound exceeds the old right bound, 
            //  replace old right bound with new right bound. i also becomes the new center. 
            if(i + rad > rb){
                c = i; 
                rb = c + rad;
            }
        }
        
        int ans = 0; 
        for(int n : p){
            // need to add 1 divide by two because the original string was modifed to two
            //  times its original length. 
            ans += (n + 1) / 2; 
        }
        
        return ans;           
    }
};
