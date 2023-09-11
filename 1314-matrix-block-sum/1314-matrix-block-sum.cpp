class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int row = mat.size();
        int col = row>0 ? mat[0].size() : 0;
        
        int dp[row+1][col+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j] + mat[i-1][j-1] - dp[i-1][j-1];
            }
        }
        
        vector<vector<int>> res(row,vector<int>(col));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int r1 = max(0, i-k); 
                int c1 = max(0, j-k);
                int r2 = min(row-1, i+k);
                int c2 = min(col-1, j+k);
                r1++; c1++; r2++; c2++;
                res[i][j] = dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
            }
        }
        return res;
    }
};