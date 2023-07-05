class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int k=0;
        int i=0;
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
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};