class Solution {
public:    
    
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vec;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            vec.push_back({i,cnt});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(vec[i].first);
        }
        return res;
    }
};