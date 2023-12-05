class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n),suf(n);
        pref[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
            suf[n-i-1]=suf[n-i]+nums[n-i-1];
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int diff=((nums[i]*i)-pref[i])+(suf[i]-(nums[i]*(n-i-1)));
            res[i]=diff;
        }
        return res;
    }
};