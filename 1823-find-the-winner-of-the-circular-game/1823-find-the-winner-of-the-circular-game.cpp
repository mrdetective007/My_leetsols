class Solution {
public:
    
    void solve(vector<int> &vec,int k,int i){
        if(vec.size()==1){
            return;
        }
        i+=k;
        int n=vec.size();
        i%=n;
        vec.erase(vec.begin()+i);
        solve(vec,k,i);
        return;
    }
    
    int findTheWinner(int n, int k) {
        vector<int> vec;
        k--;
        for(int i=0;i<n;i++){
            vec.push_back(i+1);
        }
        solve(vec,k,0);
        return vec[0];
    }
};