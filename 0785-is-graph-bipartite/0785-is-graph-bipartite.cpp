class Solution {
public:
    
    bool dfs(int i,vector<vector<int>> graph,vector<bool> &vis,vector<int> &color,int col){
        vis[i]=true;
        color[i]=col;
        for(auto x:graph[i]){
            if(color[x]==0){
                if(dfs(x,graph,vis,color,col^1)==false){
                    return false;
                }
            }else{
                if(color[i]==color[x]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false && dfs(i,graph,vis,color,0)==false){
                return false;
            }
        }
        return true;
    }
};