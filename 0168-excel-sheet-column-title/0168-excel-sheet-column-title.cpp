class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while(n>0){
            n--;
            int curr=n%26;
            n/=26;
            ans+=(char)(curr+'A');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};