class Solution {
public:
    
    void solve(int n,int k,vector<int> &nums,string &ans,vector<int> &fact){
        if(n==1){
            ans+=to_string(nums.back());
            return;
        }
        int ind=k/fact[n-1];
        if(k%fact[n-1]==0){
            ind--;
        }
        ans+=to_string(nums[ind]);
        nums.erase(nums.begin()+ind);
        k-=fact[n-1]*ind;
        solve(n-1,k,nums,ans,fact);
    }
    
    string getPermutation(int n, int k) {
        if(n==1){
            return "1";
        }
        vector<int> fact={1,1,2,6,24,120,720,5040,40320,362880};
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        string ans="";
        solve(n,k,nums,ans,fact);
        return ans;
    }
};