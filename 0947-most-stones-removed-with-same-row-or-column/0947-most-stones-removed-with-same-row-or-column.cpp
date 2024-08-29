class Solution {
public:
    
    void dfs(int i, int &cnt, vector<int> adj[], vector<bool> &vis){
        if(vis[i]){
            return;
        }
        vis[i]=true;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfs(x,cnt,adj,vis);
            }
        }
        cnt++;
        return;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        sort(stones.begin(),stones.end());
        int n=stones.size();
        vector<int> adj[n];
        vector<bool> vis(n,false);
        for(int i=0;i<n-1;i++){
            int x=stones[i][0];
            int y=stones[i][1];
            for(int j=i+1;j<n;j++){
                if(stones[j][0]==x || stones[j][1]==y){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<i<<"->";
        //     for(auto x:adj[i]){
        //         cout<<x<<",";
        //     }
        //     cout<<endl;
        // }
        int res=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            if(!vis[i]){
                dfs(i,cnt,adj,vis);
                --cnt;
                res+=cnt;
            }
        }
        // dfs(0,cnt,adj,vis);
        // return --cnt;
        return res;
    }
};