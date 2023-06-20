class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0){
            return nums;
        }
        int n=nums.size();
        vector<long long> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int> ans(n,-1);
        for(int i=k;i+k<n;i++){
            if(i-k>0){
                ans[i]=(prefix[i+k]-prefix[i-k]+nums[i-k])/(2*k+1);   
            }else{
                ans[i]=(prefix[i+k])/(2*k+1);   
            }
        }
        return ans;
    }
};