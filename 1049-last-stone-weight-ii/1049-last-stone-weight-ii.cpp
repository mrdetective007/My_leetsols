class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int w=0;
        for(auto x:stones){
            w+=x;
        }
        vector<vector<bool>> dp(n+1,vector<bool>(w+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=0;i<=w;i++){
            dp[0][i]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(j-stones[i-1]>=0){
                    dp[i][j]=dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        vector<int> v;
        for(int i=0;i<=w;i++){
            if(dp[n][i]==true){
                v.push_back(i);
            }
        }
        int mini=INT_MAX;
        for(auto x:v){
            mini=min(mini,abs(w-2*x));
        }
        return mini;
    }
};