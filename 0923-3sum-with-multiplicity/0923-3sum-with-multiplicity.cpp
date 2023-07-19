class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int cnt=0,mod=1e9+7,n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            cnt=(cnt+m[target-nums[i]])%mod;
            for(int j=0;j<i;j++){
                m[nums[i]+nums[j]]++;
            }
        }
        return cnt;
    }
};