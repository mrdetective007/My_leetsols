class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(auto x:t){
            m[x]++;
        }
        int cnt=m.size();
        int start=-1,end=-1;
        int i=0,j=0;
        int ans=INT_MAX;
        while(j<s.size()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    cnt--;
                }
            }
            if(cnt==0){
                if(j-i+1<ans){
                    start=i;
                    end=j;
                    ans=j-i+1;
                }
            }
            while(cnt==0){
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]>0){
                        cnt++;
                    }
                }
                i++;
                if(j-i+1<ans){
                    if(cnt==0){
                        start=i;
                        end=j;
                        ans=j-i+1;
                    }
                }
            }
            j++;
        }
        string temp="";
        if(start==-1 && end==-1){
            return temp;
        }
        for(int p=start;p<=end;p++){
            temp+=s[p];
        }
        return temp;
    }
};