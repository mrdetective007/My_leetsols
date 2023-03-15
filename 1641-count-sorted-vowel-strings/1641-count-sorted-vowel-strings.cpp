class Solution {
public:
    int countVowelStrings(int n) {
        // vector<int> dp = {0,1,1,1,1,1};
        // for (int i = 1; i <= n; ++i)
        //     for (int k = 1; k <= 5; ++k)
        //         dp[k] += dp[k - 1];
        // return dp[5];
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<5;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<5;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[n][4];
    }
};