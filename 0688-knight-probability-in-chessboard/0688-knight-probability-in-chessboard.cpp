class Solution {
public:
    vector<vector<vector<double>>> t;
    int dx[8]={-1,-1,-2,-2,1,1,2,2};
    int dy[8]={2,-2,1,-1,2,-2,1,-1};
    double solve(int n,int k,int r,int c)
    {
        if(r<0 || r>=n || c<0 || c>=n) return 0;
        if(k==0) return 1;
        if(t[r][c][k]!=-1) return t[r][c][k];
        double ans=0;
        for(int i=0;i<8;i++)
        {
            ans+=((0.125)*solve(n,k-1,r+dx[i],c+dy[i]));
        }
        return t[r][c][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        t=vector<vector<vector<double>>>(26,vector<vector<double>>(26,vector<double>(101,-1)));
        return solve(n,k,row,column);
    }
};