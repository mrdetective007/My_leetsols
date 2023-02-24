class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res=INT_MAX;
        int mini=INT_MAX;
        priority_queue<int> pq;
        for(auto &x:nums){
            if(x%2){
                x*=2;
            }else{
                x=x;
            }
            pq.push(x);
            mini=min(mini,x);
        }
        while(pq.top()%2==0){
            res=min(res,pq.top()-mini);
            mini=min(mini,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res,pq.top()-mini);
    }
};