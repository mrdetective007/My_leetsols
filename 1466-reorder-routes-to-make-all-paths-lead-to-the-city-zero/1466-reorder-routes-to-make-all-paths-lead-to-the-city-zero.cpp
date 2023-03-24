class Solution {
public:
    int cnt=0;
    void dfs(vector<int> adj[],vector<bool> &vis,int i){
        vis[i]=true;
        for(auto x:adj[i]){
            if(!vis[abs(x)]){
                if(x>0){
                    cnt++;
                }
                dfs(adj,vis,abs(x));
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(-x[0]);
        }
        vector<bool>vis(n,false);
        dfs(adj,vis,0);
        return cnt;
    }
};