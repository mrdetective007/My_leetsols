class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool visited[500][500];
    
    bool e(int i, int j, int n, int m, vector<vector<int>> &grid){
        if(i>=0 && i<n && j>=0 && j<m && !visited[i][j] && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    void dfs(int i, int j, vector<vector<int>> &grid){
        grid[i][j] = 0;
        visited[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();
        for(int p=0; p<4; p++){
            int newi = i+dx[p];
            int newj = j+dy[p];
            if(e(newi,newj,n,m,grid)){
                dfs(newi,newj,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(visited,false,sizeof(visited));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[0][j] == 1){
                    dfs(0,j,grid);
                }
                else if(grid[i][0] == 1){
                    dfs(i,0,grid);
                }
                else if(grid[n-1][j] == 1){
                    dfs(n-1,j,grid);
                }
                else if(grid[i][m-1] == 1){
                    dfs(i,m-1,grid);
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};