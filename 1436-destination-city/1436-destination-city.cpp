class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> m;
        for(auto x:paths){
            m[x[0]]++;
            m[x[1]]--;
        }
        for(auto x:m){
            if(x.second<0){
                return x.first;
            }
        }
        return "";
    }
};