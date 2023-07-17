class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0;
        int ans=INT_MIN;
        while(j<nums.size()){
            if(nums[j]==1){
                j++;
                ans=max(ans,j-i);
            }else{
                j++;
                i=j;
            }
        }
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};