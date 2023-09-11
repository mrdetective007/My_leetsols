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
                // cout<<x.second.size();
                for(int i=0;i<x.second.size();i++){
                    if(v.size()==x.first){
                        vec.push_back(v);
                        v.clear();
                    }
                    // cout<<"Before"<<v.size()<<endl;
                    v.push_back(x.second[i]);
                    // cout<<"After"<<v.size()<<endl;
                }
                vec.push_back(v);
            }else{
                vec.push_back(x.second);
            }
        }
        return vec;
    }
};