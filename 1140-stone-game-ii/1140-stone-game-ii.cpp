class Solution {
public:
    int dp[105][210];
    int solve(vector<int>piles,vector<int>suff,int i,int m){
        if(i==piles.size()){
            return 0;
        }
        if(i+2*m>=piles.size()){
            return suff[i];
        }
        if(dp[i][m]!=0){
            return dp[i][m];
        }
        int res=0;
        for(int x=1;x<=2*m;x++){
            res=max(res,suff[i]-solve(piles,suff,i+x,max(m,x)));
        }
        return dp[i][m]=res;
    }
    
    int stoneGameII(vector<int>& piles) {
        vector<int> suff(piles.size());
        suff[piles.size()-1]=piles[piles.size()-1];
        for(int i=piles.size()-2;i>=0;i--){
            suff[i]=suff[i+1]+piles[i];
        }
        return solve(piles,suff,0,1);
    }
};