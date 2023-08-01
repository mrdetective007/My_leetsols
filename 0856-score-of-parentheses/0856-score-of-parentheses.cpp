class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int cnt=0;
        for(auto x:s){
            if(x=='('){
                st.push(cnt);
                cnt=0;
            }else{
                cnt=st.top()+max(2*cnt,1);
                st.pop();
            }
        }
        return cnt;
    }
};