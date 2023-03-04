class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int left=-1,mini=-1,maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK||nums[i]>maxK){
                left=i;
            }
            if(nums[i]==minK){
                mini=i;
            }
            if(nums[i]==maxK){
                maxi=i;
            }
            ans+=max(0,min(mini,maxi)-left);
        }
        return ans;
    }
};