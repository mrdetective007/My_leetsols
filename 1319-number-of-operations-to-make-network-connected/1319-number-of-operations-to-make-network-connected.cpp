class Solution {
public:
    int cnt=0,ncnt=0;
    void dfs(vector<int>adj[],vector<bool>&vis,int i){
        vis[i]=true;
        ncnt++;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfs(adj,vis,x);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size=connections.size();
        vector<int>adj[n];
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(n,false);
        vector<int>cnn;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,vis,i);
                cnn.push_back(ncnt);
                ncnt=0;
            }
        }
        int a=0;
        for(auto x:cnn){
            if(x!=1){
                a+=size-x+1;
            }
        }
        if(a>=cnt-1){
            return cnt-1;
        }
        return -1;
    }
};