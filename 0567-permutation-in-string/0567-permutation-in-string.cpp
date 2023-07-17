class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        int i=0,j=0;
        vector<int> vec(26,0),v(26,0);
        for(auto x:s1){
            v[x-'a']++;
        }
        while(j<s2.size()){
            vec[s2[j]-'a']++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                bool flag=true;
                for(int p=0;p<26;p++){
                    if(v[p]!=vec[p]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
                vec[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};