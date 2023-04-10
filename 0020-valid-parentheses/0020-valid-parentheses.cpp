class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        for(auto bracket : s)
        {
            if(bracket== '(' || bracket == '{' || bracket == '[')
            {
                stk.push(bracket);
            }
            
            else
            {
                if(stk.empty()  || 
                   bracket==')' && stk.top()!='(' || 
                   bracket==']' && stk.top()!='[' || 
                   bracket=='}' && stk.top()!='{'
                  )
                {
                       return false;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        
        return stk.empty();
        
    }
};