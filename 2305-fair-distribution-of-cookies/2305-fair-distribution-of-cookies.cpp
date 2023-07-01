class Solution {
public:
    
    int ans=INT_MAX;
    
    void solve(vector<int> &vec,vector<int> &nums,int k,int i){
        if(i==nums.size()){
            int maxi=INT_MIN;
            for(auto x:vec){
                maxi=max(maxi,x);
            }
            ans=min(ans,maxi);
            return;
        }
        for(int p=0;p<k;p++){
            vec[p]+=nums[i];
            solve(vec,nums,k,i+1);
            vec[p]-=nums[i];
        }
        return;
    }
    
    int distributeCookies(vector<int>& nums, int k) {
        vector<int> vec(k,0);
        solve(vec,nums,k,0);
        return ans;
    }
};