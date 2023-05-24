class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=INT_MIN;
        long long sum=0;
        int n=nums1.size();
        priority_queue<pair<int,int>> maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mini;
        for(int i=0;i<n;i++){
            maxi.push({nums1[i],i});
        }
        while(!maxi.empty() && k>0){
            auto top=maxi.top();
            sum+=top.first;
            mini.push({nums2[top.second],top.second});
            maxi.pop();
            k--;
        }
        int minim=mini.top().first;
        ans=max(ans,(long long)(sum*minim));
        while(!maxi.empty()){
            auto p=mini.top();
            sum-=nums1[p.second];
            mini.pop();
            auto q=maxi.top();
            sum+=q.first;
            mini.push({nums2[q.second],q.second});
            maxi.pop();
            minim=mini.top().first;
            ans=max(ans,(long long)(sum*minim));
        }
        return ans;
    }
};