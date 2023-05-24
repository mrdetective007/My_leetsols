class Solution {
public:
    
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<nums1.size();i++){
            vec[i]={nums1[i],nums2[i]};
        }
        sort(vec.begin(),vec.end(),cmp);
        priority_queue<int> q;
        long long ans=0,sum=0;
        for(int i=0;i<k-1;i++){
            sum+=vec[i].first;
            q.push(-vec[i].first);
        }
        for(int i=k-1;i<nums1.size();i++){
            sum+=vec[i].first;
            q.push(-vec[i].first);
            ans=max(ans,(long long)(sum*vec[i].second));
            sum+=q.top();
            q.pop();
        }
        return ans;
    }
};