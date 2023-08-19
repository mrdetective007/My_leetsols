class Solution {
public:
    int mst(vector<pair<int,int>> a[],int n)
    {
        int ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        vector<int> vis(n,0);
        
        while(pq.size())
        {
            auto curr = pq.top();pq.pop();
            if(vis[curr.second])continue;
            vis[curr.second] = 1;
            ans += curr.first;
            
            for(auto it:a[curr.second])
            {
                if(vis[it.first]==0)
                {
                    pq.push({it.second,it.first});
                }
            }
        }
        return ans;
    }
    
    bool check(vector<int> &edge,int sv,pair<int,int> &it)
    {
        if(edge[0] == sv and edge[1]==it.first and edge[2]==it.second)return 1;
        if(edge[1] == sv and edge[0]==it.first and edge[2]==it.second)return 1;
        return 0;
    }
    
    int nmst(vector<pair<int,int>> a[],int n,vector<int> &edge,int flag)
    {
        int ans = 0;
        if(flag)
        {
            ans = edge[2];
            for(auto &it:a[edge[0]])
            {
                if(it.first==edge[1])
                {
                    it.second = 0;
                }
            }
            
            for(auto &it:a[edge[1]])
            {
                if(it.first==edge[0])
                {
                    it.second = 0;
                }
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        vector<int> vis(n,0);
        
        while(pq.size())
        {
            auto curr = pq.top();pq.pop();
            if(vis[curr.second])continue;
            vis[curr.second] = 1;
            ans += curr.first;
            
            for(auto it:a[curr.second])
            {
                if(flag==0)
                {
                    if(vis[it.first]==0 and (!check(edge,curr.second,it)))
                    {
                        pq.push({it.second,it.first});
                    }
                }
                else
                {
                    if(vis[it.first]==0)
                    {
                        pq.push({it.second,it.first});
                    }
                }
            }
        }
        
        if(flag)
        {
            for(auto &it:a[edge[0]])
            {
                if(it.first==edge[1])
                {
                    it.second = edge[2];
                }
            }
            
            for(auto &it:a[edge[1]])
            {
                if(it.first==edge[0])
                {
                    it.second = edge[2];
                }
            }
        }
        
        for(auto it:vis)
            if(!it)return -1;
        
        return ans;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        vector<pair<int,int>> a[n];
        for(auto it:edges)
        {
            a[it[0]].push_back({it[1],it[2]});
            a[it[1]].push_back({it[0],it[2]});
        }
        
        int val = mst(a,n);
        
        vector<int> critical;
        vector<int> pseudo;
        for(int i = 0;i<edges.size();i++)
        {
            //forcefully taken this edge
            int nval = nmst(a,n,edges[i],1);
            if(nval>val)
            {
                continue;
            }
            else 
            {
                //forcefully ignored this edge
                nval = nmst(a,n,edges[i],0);
                if(nval>val or nval==-1)
                    critical.push_back(i);
                else
                    pseudo.push_back(i);
            }
        }
        
        ans.push_back(critical);
        ans.push_back(pseudo);
        
        return ans;
    }
};