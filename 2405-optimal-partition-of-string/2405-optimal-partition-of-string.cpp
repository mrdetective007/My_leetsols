class Solution {
public:
    int partitionString(string s) {
        int cnt=1;
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                cnt++;  
                mp.clear();
            }
            mp[s[i]]++;
        }
        return cnt;
    }
};