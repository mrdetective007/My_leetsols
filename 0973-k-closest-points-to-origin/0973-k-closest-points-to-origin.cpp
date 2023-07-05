#define ppi pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ppi> pq;
        for(int i=0;i<points.size();i++){
            int dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dis,{points[i][0],points[i][1]}});
                if(pq.size()>k){
                    pq.pop();
                }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> v(2);
            v[0]=pq.top().second.first;
            v[1]=pq.top().second.second;
            ans.push_back(v);
            pq.pop();
        }
        return ans;
    }
};