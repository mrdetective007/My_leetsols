class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<=1){
            return 0;
        }
        vector<int> dp(s.size(),0);
        int currmax=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=(i-2>=0)?dp[i-2]+2:2;
                    currmax=max(currmax,dp[i]);
                }else{
                    if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                        dp[i]=dp[i-1]+2+((i-dp[i-1]-2>=0)?dp[i-dp[i-1]-2]:0);
                        currmax=max(currmax,dp[i]);
                    }
                }
            }
        }
        return currmax;
    }
};