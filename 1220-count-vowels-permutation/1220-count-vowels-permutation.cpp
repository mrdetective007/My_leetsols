class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> curr(5,1),next(5);
        int mod=1000000007;
        for(int i=1;i<n;i++){
            next[0]=curr[1];
            next[1]=(curr[0]+curr[2])%mod;
            next[2]=(((curr[0]+curr[1])%mod+curr[3])%mod+curr[4])%mod;
            next[3]=(curr[2]+curr[4])%mod;
            next[4]=curr[0];
            vector<int> &temp=curr;
            curr=next;
            next=temp;
        }
        int cnt=0;
        for(auto x:curr){
            cnt=(cnt+x)%mod;
        }
        return cnt;
    }
};