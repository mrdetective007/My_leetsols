class Solution {
public:
    
    vector<vector<vector<int>>> dp;
    int mod=1000000007;
    int solve(int n,int mini,vector<int> &grp,vector<int> &profit,int i){
        if(n<0){
            return 0;
        }
        if(i==grp.size()){
            if(mini>0){
                return 0;
            }
            else 
                return 1;
        }
        if(mini<0){
            mini=0;
        }
        if(dp[mini][n][i]!=-1){
            return dp[mini][n][i];
        }
        int cnt1=solve(n-grp[i],mini-profit[i],grp,profit,i+1);
        int cnt2=solve(n,mini,grp,profit,i+1);
        return dp[mini][n][i]=(cnt1+(long long)cnt2)%mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int sz = group.size();
        dp = vector<vector<vector<int>>>(minProfit + 1, vector<vector<int>>(n + 1, vector<int>(sz, -1)));
        int ans=solve(n,minProfit,group,profit,0);
        return ans;
    }
};