class Solution {
public:
    bool isValid(string s) {
        
        vector<char> stack; 
        
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push_back(s[i]);
            }else{
                // watch out for the case where"]", "}" is the only input. 
                if((s[i] == ')' || s[i] == ']' || s[i] == '}') && stack.empty()){
                    return false;
                }
                else if(s[i] == ')' && stack.back() != '('){
                    return false; 
                }else if(s[i] == '}' && stack.back() != '{'){
                    return false;
                }else if(s[i] == ']' && stack.back() != '['){
                    return false; 
                }else{
                    stack.pop_back();
                }
            }
        }
        
        // watches out for the case where "[", "(", "{" is the only input or left over in stack.
        return stack.empty(); 
    
    
    }

};
