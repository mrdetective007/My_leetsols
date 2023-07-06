class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        priority_queue<int> pq;
        for(auto x:piles){
            pq.push(x);
        }
        while(k--){
            int curr=pq.top();pq.pop();
            curr-=(curr/2);
            pq.push(curr);
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};