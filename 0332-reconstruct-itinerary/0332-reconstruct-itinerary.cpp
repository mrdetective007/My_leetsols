class Solution {
public:
    
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> m;
    vector<string> res;
    
    void solve(string s){
        auto &x=m[s];
        while(!x.empty()){
            string next=x.top();
            x.pop();
            solve(next);
        }
        res.push_back(s);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x:tickets){
            m[x[0]].push(x[1]);
        }
        solve("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};