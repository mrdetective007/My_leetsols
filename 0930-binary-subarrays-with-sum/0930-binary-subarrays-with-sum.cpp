class Solution {
public:
    
    int ok(vector<int>& nums, int goal){
        int cnt=0,sum=0;
        int i=0,j=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum>goal){
                while(i<=j && sum>goal){
                    sum-=nums[i];
                    i++;
                }
            }
            cnt+=j-i+1;   
            j++;
        }
        return cnt;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ok(nums,goal)-ok(nums,goal-1);
    }
};