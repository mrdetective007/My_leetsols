class Solution {
public:
    vector<bool> vis;
    int dfs(int i,vector<int> adj[],vector<int> &informTime){
        vis[i]=true;
        int cnt=0;
        for(auto x:adj[i]){
            if(!vis[x]){
                cnt=max(cnt,dfs(x,adj,informTime));
            }
        }
        return cnt+informTime[i];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        int head=0;
        for(int i=0;i<n;i++){
            if(manager[i]==-1){
                head=i;
                break;
            }
        }
        vis.resize(n,false);
        int ans=dfs(head,adj,informTime);
        return ans;
    }
};