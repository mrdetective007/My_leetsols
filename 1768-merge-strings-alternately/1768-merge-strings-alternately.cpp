class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string ans="";
        bool f=true;
        while(i<word1.size()&&j<word2.size()){
            if(f){
                ans+=word1[i];
                i++;
                f=false;
            }else{
                ans+=word2[j];
                j++;
                f=true;
            }
        }
        while(i<word1.size()){
            ans+=word1[i];
            i++;
        }
        while(j<word2.size()){
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};