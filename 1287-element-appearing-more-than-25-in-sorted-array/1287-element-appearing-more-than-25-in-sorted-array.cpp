class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> m;
        int cnt=0;
        for(auto x:arr){
            m[x]++;
            cnt++;
        }
        for(auto x:m){
            if(x.second>(cnt/4)){
                return x.first;
            }
        }
        return 0;
    }
};