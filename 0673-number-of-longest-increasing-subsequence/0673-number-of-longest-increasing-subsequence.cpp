class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),count(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&dp[i]<1+dp[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j]&&dp[i]==1+dp[j]){
                    count[i]+=count[j];
                }
            }
        }
        int maxi=*max_element(dp.begin(),dp.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=count[i];
            }
        }
        return ans;
    }
};