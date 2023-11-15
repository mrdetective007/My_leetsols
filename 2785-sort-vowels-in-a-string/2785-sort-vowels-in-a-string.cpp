class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U'){
                v.push_back(x);
                s[i]='#';
            }
        }
        sort(v.begin(),v.end());
        int n=v.size();
        int j=0;
        for(int i=0;i<s.size() && j<n;i++){
            if(s[i]=='#'){
                s[i]=v[j];
                j++;
            }
        }
        return s;
    }
};