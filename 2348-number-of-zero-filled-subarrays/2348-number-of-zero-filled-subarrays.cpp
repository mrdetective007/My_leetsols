class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans=0,cnt=0;
        for(auto x:nums){
            if(x==0){
                cnt++;
                ans+=cnt;
            }else{
                cnt=0;
            }
        }
        return ans;
    }
};