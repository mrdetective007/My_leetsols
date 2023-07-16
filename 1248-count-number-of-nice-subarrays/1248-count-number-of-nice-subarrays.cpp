class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &x:nums){
            if(x%2){
                x=1;
            }else{
                x=0;
            }
        }
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};