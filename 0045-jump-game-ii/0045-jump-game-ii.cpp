class Solution {
public:
    int dp[10005];
    int solve(int i,vector<int> &nums){
        if(i==nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini=1e9;
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()){
                mini=min(mini,1+solve(i+j,nums));
            }
        }
        return dp[i]=mini;
    }
    
    
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};