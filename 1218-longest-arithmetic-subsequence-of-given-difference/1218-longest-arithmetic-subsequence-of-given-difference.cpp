class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        for(int i=0;i<arr.size();i++){
            dp[arr[i]]=1+dp[arr[i]-difference];
        }
        int res=INT_MIN;
        for(auto x:dp){
            res=max(res,x.second);
        }
        return res;
    }
};