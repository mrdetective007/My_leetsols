class Solution {
public:
    vector<double> dijkstra(int i, vector<pair<int,double>> adj[], vector<bool> processed, int n){
        vector<double> distance(n,0);
        distance[i] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,i});
        while(!pq.empty()){
            int a = pq.top().second;
            pq.pop();
            if(processed[a] == true){
                continue;
            }
            processed[a] = true;
            for(auto x:adj[a]){
                int b;
                double w;
                b = x.first;
                w = x.second;
                if(distance[b]<distance[a]*w){
                    distance[b] = distance[a]*w;
                    pq.push({distance[b],b});
                }
            }
        }
        return distance;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<bool> processed(n,false);
        vector<double> vec = dijkstra(start,adj,processed,n);
        return vec[end];
    }
};