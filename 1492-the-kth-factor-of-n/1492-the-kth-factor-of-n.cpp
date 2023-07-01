class Solution {
public:
    int kthFactor(int n, int k) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(n%i==0 && k>0){
                k--;
                ans=i;
            }
            else if(k==0){
                break;
            }
        }
        if(k>0){
            return -1;
        }
        return ans;
    }
};