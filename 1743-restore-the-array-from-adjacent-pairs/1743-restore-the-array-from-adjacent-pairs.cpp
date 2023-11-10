class Solution {
public:
    
    vector<int> ans;
    set<int> s;
    void solve(int ele,unordered_map<int,vector<int>> &m){
        ans.push_back(ele);
        s.insert(ele);
        for(auto x:m[ele]){
            if(!s.contains(x)){
                solve(x,m);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> m;
        for(auto x:adjacentPairs){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        int ele=0;
        for(auto x:m){
            if(x.second.size()==1){
                ele=x.first;
                break;
            }
        }
        solve(ele,m);
        return ans;
    }
};