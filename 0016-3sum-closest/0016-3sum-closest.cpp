class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            while(l!=r){
                int c=nums[i]+nums[l]+nums[r];
                if(l!=i && r!=i && abs(c-target)<mini){
                    mini=abs(c-target);
                    ans=c;
                }
                else if(c<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};