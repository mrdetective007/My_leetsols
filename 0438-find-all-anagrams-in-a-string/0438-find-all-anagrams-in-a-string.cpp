class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        vector<int> ans;
        if(m>n){
            return {};
        }
        vector<int> a(26,0);
        for(auto x:p){
            a[x-'a']++;
        }
        vector<int> b(26,0);
        for(int i=0;i<m;i++){
            b[s[i]-'a']++;
        }
        bool flag=true;
        // for(int i=0;i<26;i++){
        //     if(a[i]!=b[i]){
        //         flag=false;
        //         break;
        //     }
        // }
        // if(flag){
        //     ans.push_back(0);
        // }
        // flag=true;
        int start=0,end=m-1;
        while(end<n){
            flag=true;
            for(int j=0;j<26;j++){
               if(a[j]!=b[j]){
                   flag=false;
                   break;
               }
            }
            if(flag){
                ans.push_back(start);
            }
            b[s[start]-'a']--;
            start++;
            end++;
            if(end!=n){
                b[s[end]-'a']++;
            }
        }
        return ans;
    }
};