class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=s[i-1]+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int sum=0;
        for(auto x:s){
            sum+=x;
        }
        for(auto x:t){
            sum+=x;
        }
        return sum-2*dp[n][m];
    }
};