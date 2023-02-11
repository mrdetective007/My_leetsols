class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:redEdges){
            adj[x[0]].push_back({x[1],0});
        }
        for(auto x:blueEdges){
            adj[x[0]].push_back({x[1],1});
        }
        vector<int> ans(n,-1);
        vector<vector<bool>> vis(n,vector<bool>(2));
        queue<vector<int>> q;
        q.push({0,0,-1});
        vis[0][0]=vis[0][1]=true;
        ans[0]=0;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto x:adj[curr[0]]){
                if(!vis[x.first][x.second] && x.second!=curr[2]){
                    vis[x.first][x.second]=true;
                    q.push({x.first,1+curr[1],x.second});
                    if(ans[x.first]==-1){
                        ans[x.first]=1+curr[1];
                    }
                }
            }
        }
        return ans;
    }
};