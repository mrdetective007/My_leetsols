class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s(32,0), g(32,0);
        int i=31;
        while(start>0){
            s[i--]=start%2;
            start/=2;
        }
        i=31;
        while(goal>0){
            g[i--]=goal%2;
            goal/=2;
        }
        int cnt=0;
        for(int i=0;i<32;i++){
            if(s[i]!=g[i]){
                cnt++;
            }
        }
        return cnt;
    }
};