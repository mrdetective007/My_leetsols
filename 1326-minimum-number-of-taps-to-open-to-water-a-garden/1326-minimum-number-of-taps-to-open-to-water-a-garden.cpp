class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> t(n+1, n+2);
        t[0] = 0;
        for(int i = 0; i<n+1; i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            
            for(int j = l+1; j<=r; j++){              
                t[j] = min(t[j], t[l]+1);
            }
        }
        if(t[n]>n+1){
            return -1;
        }
        return t[n];
    }
};