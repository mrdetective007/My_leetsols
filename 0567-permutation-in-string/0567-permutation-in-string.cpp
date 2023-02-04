class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size(),m=s1.size();
        if(m>n){
            return false;
        }
        vector<int> a(26,0);
        for(auto x:s1){
            a[x-'a']++;
        }
        vector<int> b(26,0);
        int start=0,end=m-1;
        for(int i=start;i<=end;i++){
            b[s2[i]-'a']++;
        }
        //end++;
        bool ans=true;
        while(end<n){
            ans=true;
            for(int i=0;i<26;i++){
                if(a[i]!=b[i]){
                    ans=false;
                    break;
                }
            }
            if(ans){
                return true;
            }
            b[s2[start]-'a']--;
            start++;
            end++;
            if(end!=n){
                b[s2[end]-'a']++;
            }
        }
        return false;
    }
};