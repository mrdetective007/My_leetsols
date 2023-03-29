class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size(),curr=0,ans=0;
        for(int i=n-1;i>=0&&satisfaction[i]>-curr;i--){
            curr+=satisfaction[i];
            ans+=curr;
        }
        return ans;
    }
};