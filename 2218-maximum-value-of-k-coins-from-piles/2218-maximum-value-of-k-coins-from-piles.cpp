class Solution {
public:
    int dp[2005][2005]={0};
    int solve(int ind,vector<vector<int>>&piles,int k){
        if(ind>=piles.size()||k==0){
            return 0;
        }
        if(dp[ind][k]!=0){
            return dp[ind][k];
        }
        int res=0,summ=0;
        res=max(res,solve(ind+1,piles,k));
        for(int i=0;i<piles[ind].size();i++){
            summ+=piles[ind][i];
            if(k-i-1>=0){
                res=max(res,summ+solve(ind+1,piles,k-i-1));
            }
        }
        return dp[ind][k]=res;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        return solve(0,piles,k);
    }
};