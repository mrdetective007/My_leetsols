class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> onerows(n),zerorows(n);
        vector<int> onecols(m),zerocols(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    onerows[i]++;
                    onecols[j]++;
                }else{
                    zerorows[i]++;
                    zerocols[j]++;
                }
            }
        }
        vector<vector<int>> diff(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j]=onerows[i]+onecols[j]-zerorows[i]-zerocols[j];
            }
        }
        return diff;
    }
};