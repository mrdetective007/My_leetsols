class Solution {
public:
    int dp[1001]={0};
    int solve(vector<int> &nums,int t,int i){
        if(i==0){
            return 0;
        }
        if(dp[i]!=0){
            return dp[i];
        }
        int maxi=-1;
        for(int j=0;j<i;j++){
            int diff=nums[i]-nums[j];
            if(diff>=-t && diff<=t){
                maxi=max(maxi,1+solve(nums,t,j));
            }
        }
        if(maxi==0){
            return dp[i]=-1;
        }
        return dp[i]=maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        return solve(nums,target,nums.size()-1);
    }
};