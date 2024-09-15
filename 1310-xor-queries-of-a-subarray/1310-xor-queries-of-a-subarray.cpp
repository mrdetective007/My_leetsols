class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=arr[i]^prefix[i-1];
        }
        int m=queries.size();
        vector<int> vec(m,0);
        for(int i=0;i<m;i++){
            int f=queries[i][0];
            int l=queries[i][1];
            if(f==0){
                vec[i]=prefix[l];
            }
            else{
                vec[i]=arr[f]^prefix[f]^prefix[l];
            }
        }
        return vec;
    }
};