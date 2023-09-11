class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> m;
        for(int i=0;i<groupSizes.size();i++){
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> vec;
        for(auto x:m){
            if(x.second.size()>x.first){
                vector<int> v;
                for(int i=0;i<x.second.size();i++){
                    if(v.size()==x.first){
                        vec.push_back(v);
                        v.clear();
                    }
                    v.push_back(x.second[i]);
                }
                vec.push_back(v);
            }else{
                vec.push_back(x.second);
            }
        }
        return vec;
    }
};