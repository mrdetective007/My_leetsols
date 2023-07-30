class Solution {
public:
    int strangePrinter(string s) {
        if(s == "") return 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, n));
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int j = 0; j < n; j++)
            for(int i = j; i >= 0; i--)
                for(int k = i; k < j; k++)
                    if(s[k] == s[j]) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] - 1);
                    else dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);

        return dp[0][n-1];
    }
};