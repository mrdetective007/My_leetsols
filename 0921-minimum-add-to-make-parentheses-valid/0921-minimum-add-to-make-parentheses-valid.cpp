class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stck;
        stck.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!stck.empty() && s[i]==')' && stck.top()=='('){
                stck.pop();
            }else{
                stck.push(s[i]);
            }
        }
        return stck.size();
    }
};