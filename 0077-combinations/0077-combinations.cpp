class Solution {
public:    
    vector<vector<int>> ans;
    void solve(vector<int> &vec,int n,int k,int i){
        if(vec.size()==k){
            ans.push_back(vec);
            return;
        }
        if(i<n){
            vec.push_back(i+1);
            solve(vec,n,k,i+1);
            vec.pop_back();
            solve(vec,n,k,i+1);
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            vec[i]=i+1;
        }
        vector<int> s;
        solve(s,n,k,0);
        return ans;
    }
};