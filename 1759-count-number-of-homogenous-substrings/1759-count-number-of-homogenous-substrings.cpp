class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7;
        int curr=0,cnt=0,ans=0;
        for(auto x:s){
            if(x-'a'==curr){
                cnt++;
            }else{
                cnt=1;
            }
            curr=x-'a';
            ans=(ans+cnt)%mod;
        }
        return ans;
    }
};