class Solution {
public:
    double sol(double x,int n){
        if(x==0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        double res=sol(x*x,n/2);
        if(n%2){
            return x*res;
        }
        return res;
    }
    double myPow(double x, int n) {
        double ans=sol(x,abs(n));
        if(n<0){
            return 1/ans;
        }
        return ans;
    }
};