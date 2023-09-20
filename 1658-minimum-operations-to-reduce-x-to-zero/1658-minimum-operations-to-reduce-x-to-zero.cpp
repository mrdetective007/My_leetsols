class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=0;
        for(auto y:nums){
            tot+=y;
        }
        tot-=x;
        if(tot==0){
            return nums.size();
        }
        int i=0,j=0;
        int len=0,sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum>tot){
                while(i<nums.size() && sum>tot){
                    sum-=nums[i];
                    i++;
                }
            }
            if(sum==tot){
                len=max(len,j-i+1);
            }
            j++;
        }
        if(len==0){
            return -1;
        }
        return nums.size()-len;
    }
};