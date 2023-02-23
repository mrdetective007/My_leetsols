class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vec;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        priority_queue<int> pq;
        int j=0;
        for(int i=0;i<k;i++){
            while(j<vec.size()&&vec[j].first<=w){
                pq.push(vec[j].second);
                j++;
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};