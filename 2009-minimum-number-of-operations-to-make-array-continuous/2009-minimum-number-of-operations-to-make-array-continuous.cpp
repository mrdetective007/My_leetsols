class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>unique;
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(auto x:s){
            unique.push_back(x);
        }
        int ans=INT_MAX;
        for(int i=0;i<unique.size();i++){
            int start = unique[i];
            int last = start+n-1;
            auto it=upper_bound(unique.begin(),unique.end(),last);
            int len = it- unique.begin();
            ans = min(ans,n-(len-i));
        }
       return ans;
    }
};