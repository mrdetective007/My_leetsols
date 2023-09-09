class Solution {
public:
    int combinationSum4(vector<int>& nums, int k) {
        vector<unsigned int> dp(k+1);
        dp[0]=1;
        for(int i=1;i<k+1;i++){
            for(auto x:nums){
                if(i-x>=0){
                    dp[i]+=dp[i-x];
                }
            }
        }
        return dp[k];
    }
};