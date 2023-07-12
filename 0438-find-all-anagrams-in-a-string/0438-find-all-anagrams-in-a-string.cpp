class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec(26,0),v(26,0),ans;
        for(auto x:p){
            vec[x-'a']++;
        }
        int i=0,j=0,k=p.size();
        while(j<s.size()){
            v[s[j]-'a']++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                bool flag=true;
                for(int x=0;x<26;x++){
                    if(vec[x]!=v[x]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans.push_back(i);
                }
                v[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};