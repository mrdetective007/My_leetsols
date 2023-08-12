class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        if(mat[0][0]==1){
            return 0;
        }
        if(n==1 && m==1){
            if(mat[0][0]==1){
                return 0;
            }
            return 1;
        }
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dis(n,vector<int>(m,0));
        dis[0][0]=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto curr=q.front();
                q.pop();
                if(vis[curr.first][curr.second]){
                    continue;
                }
                vis[curr.first][curr.second]=true;
                if(curr.first+1>=0 && curr.first+1<n && curr.second>=0 && curr.second<m && !vis[curr.first+1][curr.second] && mat[curr.first+1][curr.second]!=1){
                    q.push({curr.first+1,curr.second});
                    dis[curr.first+1][curr.second]+=dis[curr.first][curr.second];
                }
                if(curr.first>=0 && curr.first<n && curr.second+1>=0 && curr.second+1<m && !vis[curr.first][curr.second+1] && mat[curr.first][curr.second+1]!=1){
                    q.push({curr.first,curr.second+1});
                    dis[curr.first][curr.second+1]+=dis[curr.first][curr.second];
                }
            }
        }
        return dis[n-1][m-1];
    }
};