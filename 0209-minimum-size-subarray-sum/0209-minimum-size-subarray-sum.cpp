class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;
        int n=nums.size();
        vector<int>prefix(n+1,0);
        prefix[0]=0;
        for(int i=1;i<n+1;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        for(int i=1;i<n+1;i++){
            if(prefix[i]>=target){
                auto it=upper_bound(prefix.begin(),prefix.begin()+i,prefix[i]-target);
                if(it!=prefix.end()){
                    res=min(res,i-(int)(it-prefix.begin())+1);
                }
            }
        }
        if(res==INT_MAX){
            return 0;
        }
        return res;
    }
};