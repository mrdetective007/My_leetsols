class Solution {
public:
    
    static bool cmp(vector<int> a,vector<int> b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int cnt=1;
        int temp=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>temp){
                cnt++;
                temp=pairs[i][1];
            }
        }
        return cnt;
    }
};