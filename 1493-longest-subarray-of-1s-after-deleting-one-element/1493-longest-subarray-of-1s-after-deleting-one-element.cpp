class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=INT_MIN;
        int i=0,k=1;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                k--;
            }
            while(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};