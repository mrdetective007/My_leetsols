class Solution {
public:
    bool solve(string s){
        string temp=s;
        reverse(temp.begin(),temp.end());
        return s==temp;
    }
    int countSubstrings(string s) {
        int cnt=s.size();
        for(int i=0;i<s.size();i++){
            string a="";
            a+=s[i];
            for(int j=i+1;j<s.size();j++){
                a+=s[j];
                if(solve(a)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};