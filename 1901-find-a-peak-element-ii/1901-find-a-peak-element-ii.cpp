class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<pair<int,pair<int,int>>> vec;
        for(int i=0;i<mat.size();i++){
            int j=max_element(mat[i].begin(),mat[i].end())-mat[i].begin();
            vec.push_back({mat[i][j],{i,j}});
        }
        sort(vec.begin(),vec.end());
        return {vec[vec.size()-1].second.first,vec[vec.size()-1].second.second};
    }
};