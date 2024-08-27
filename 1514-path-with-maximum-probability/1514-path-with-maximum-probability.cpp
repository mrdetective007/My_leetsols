class Solution {
public:
    
    double dij(int n, int s, int e, vector<pair<int,double>> adj[]){
        vector<double> dis(n,0);
        dis[s]=1;
        vector<bool> mark(n,false);
        priority_queue<pair<double,int>> pq;
        pq.push({dis[s],s});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(mark[x.second]){
                continue;
            }
            mark[x.second]=true;
            for(auto y:adj[x.second]){
                if(dis[y.first]<dis[x.second]*y.second){
                    dis[y.first]=dis[x.second]*y.second;
                    pq.push({dis[y.first],y.first});
                }
            }
        }
        return dis[e];
    }
    
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        double ans=dij(n,start_node,end_node,adj);
        return ans;
    }
};