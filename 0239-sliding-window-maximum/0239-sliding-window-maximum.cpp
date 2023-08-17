class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int i=0,j=0;
        // priority_queue<pair<int,int>> pq;
        // vector<int> ans;
        // while(j<nums.size()){
        //     pq.push({nums[j],j});
        //     if(j-i+1<k){
        //         j++;
        //     }
        //     else if(j-i+1==k){
        //         while(pq.top().second<i){
        //             pq.pop();
        //         }
        //         ans.push_back(pq.top().first);
        //         i++;
        //         j++;
        //     }
        // }
        // return ans;
        vector<int> ans;
        multiset<int> s;
        for(int i=0;i<k;i++){
            s.insert(nums[i]);
        }
        ans.push_back(*s.rbegin());
        for(int i=k;i<nums.size();i++){
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};