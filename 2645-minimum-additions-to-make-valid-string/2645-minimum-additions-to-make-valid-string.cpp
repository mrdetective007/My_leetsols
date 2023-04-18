class Solution {
public:
    int addMinimum(string word) {
        int i=0,cnt=0;
        while(i<word.size()){
            int res=0;
            if(word[i]=='a'){
                i++;
                res++;
            }
            if(word[i]=='b'){
                i++;
                res++;
            }
            if(word[i]=='c'){
                i++;
                res++;
            }
            cnt+=3-res;
        }
        return cnt;
    }
};