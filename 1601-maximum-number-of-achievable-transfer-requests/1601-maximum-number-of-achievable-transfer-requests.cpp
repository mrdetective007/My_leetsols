class Solution {
public:
    
    int ans=0;
    
    void solve(int i,vector<vector<int>> &requests,vector<int> &vec,int cnt){
        if(i==requests.size()){
            for(auto x:vec){
                if(x!=0){
                    return;
                }
            }
            ans=max(ans,cnt);
            return;
        }
        vec[requests[i][0]]--;
        vec[requests[i][1]]++;
        solve(i+1,requests,vec,cnt+1);
        vec[requests[i][0]]++;
        vec[requests[i][1]]--;
        solve(i+1,requests,vec,cnt);
        return;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> vec(n,0);
        int cnt=0;
        solve(0,requests,vec,cnt);
        return ans;
    }
};