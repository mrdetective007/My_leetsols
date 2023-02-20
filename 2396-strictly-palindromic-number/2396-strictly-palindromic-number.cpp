class Solution {
public:
    
    bool ispalin(string s){
        string temp=s;
        reverse(s.begin(),s.end());
        return s==temp;
    }
    
    string bases(int n,int i){
        string s="";
        while(n>0){
            int rem=n%i;
            s+=to_string(rem);
            n/=i;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<n-1;i++){
            string ans=bases(n,i);
            if(!ispalin(ans)){
                return false;
            }
        }
        return true;
    }
};