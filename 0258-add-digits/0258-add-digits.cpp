class Solution {
public:
    
    int solve(int num){
        int ans=0;
        while(num>0){
            ans+=num%10;
            num/=10;
        }
        return ans;
    }
    
    int addDigits(int num) {
        int ans=solve(num);
        int fans=solve(ans);
        if(fans>=10){
            int ans1=solve(fans);
            return ans1;
        }
        return fans;
    }
};