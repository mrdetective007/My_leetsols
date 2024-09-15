class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> vec(26,0);
        for(auto x:allowed){
            vec[x-'a']=1;
        }
        int cnt=0;
        for(auto x:words){
            bool flag=true;
            for(auto y:x){
                if(vec[y-'a']){
                    flag&=true;
                }else{
                    flag&=false;
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt;
    }
};