class Solution {
public:
    
    void dfs(vector<int>adj[],vector<bool>&vis,int i,long long int &cunt){
        vis[i]=true;
        cunt++;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfs(adj,vis,x,cunt);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(n,false);
        vector<int> cnt;
        long long int prod=0;
        long long int rem=n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long int cunt=0;
                dfs(adj,vis,i,cunt);
                prod+=cunt*(rem-cunt);
                rem-=cunt;
            }
        }
        return prod;
    }
};