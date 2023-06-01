class Solution {
public:
    int visited[500][500];
    int dx[8] = {-1,-1,0,+1,+1,+1,0,-1};
    int dy[8] = {0,+1,+1,+1,0,-1,-1,-1};
    bool e(int i, int j, int n, int m, vector<vector<int>> &grid){
        if(i>=0 && i<n && j>=0 && j<m && !visited[i][j] && grid[i][j] == 0){
            return true;
        }
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int distance[n][m];
        memset(visited,false,sizeof(visited));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        distance[0][0] = 1;
        if(grid[0][0]!=0){
            return -1;
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            int t = distance[i][j];
            q.pop();
            for(int p=0; p<8; p++){
                int newi = i+dx[p];
                int newj = j+dy[p];
                if(e(newi,newj,n,m,grid)){
                    visited[newi][newj] = true;
                    distance[newi][newj] = t+1;
                    if(newi == n-1 && newj == m-1){
                        return distance[newi][newj];
                    }
                    q.push({newi,newj});
                }
            }
        }
        if(visited[n-1][m-1])
            return distance[n-1][m-1];
        return -1;
    }
};