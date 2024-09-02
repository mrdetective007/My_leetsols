class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>> big;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> small;
        int n=arrays.size();
        for(int i=0;i<n;i++){
            small.push({arrays[i][0],i});
            big.push({arrays[i].back(),i});
        }
        int diff=0;
        if(small.top().second!=big.top().second){
            return abs(big.top().first-small.top().first);
        }
        auto maxi=big.top();
        auto mini=small.top();
        big.pop();
        small.pop();
        diff=max(abs(maxi.first-small.top().first), abs(big.top().first-mini.first));
        return diff;
    }
};