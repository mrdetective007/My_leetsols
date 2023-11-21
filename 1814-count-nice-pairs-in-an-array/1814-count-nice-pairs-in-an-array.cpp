class Solution {
public:
    int rev(int n){
        // string s=to_string(n);
        // while(s.back()=='0'){
        //     s.pop_back();
        // }
        // reverse(s.begin(),s.end());
        // return stoi(s);
        int rem=0;
        while(n>0){
            rem=rem*10+n%10;
            n/=10;
        }
        return rem;
    }
    int countNicePairs(vector<int>& nums) {
        int mod=1e9+7;
        // vector<int> vec;
        // for(auto x:nums){
        //     vec.push_back(rev(x));
        // }
        // vector<int> pre(nums.size()),suf(nums.size());
        // for(int i=0;i<nums.size();i++){
        //     pre[i]=nums[i]-vec[i];
        //     suf[i]=vec[i]-nums[i];
        // }
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
        unordered_map<int,long> m;
        for(auto x:nums){
            m[x]++;
        }
        long cnt=0;
        for(auto x:m){
            cnt=(cnt+(x.second*(x.second-1))/2)%mod;
        }
        return cnt;
    }
};