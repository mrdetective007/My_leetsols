class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int L[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0) L[i][j] =0;
                else
                    if(s1[i-1]==s2[j-1])
                        L[i][j] = L[i-1][j-1] + s1[i-1];
                else
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
        int sum =0;
        for(int i=0;i<n;i++)
            sum += s1[i];
        for(int j =0;j<m;j++)
            sum +=s2[j];
      
        return sum-2*L[n][m];
    }
};