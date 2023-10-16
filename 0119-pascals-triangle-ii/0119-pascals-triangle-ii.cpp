class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1);
        vector<int> temp;
        temp.push_back(1);
        dp[0]=(temp);
        for(int i=1;i<=rowIndex;i++){
            vector<int> t(i+1);
            t[0]=t[i]=1;
            for(int j=1;j<=i-1;j++){
                t[j]=dp[i-1][j]+dp[i-1][j-1];
            }
            dp[i]=(t); 
        }
        return dp[rowIndex];
    }
};