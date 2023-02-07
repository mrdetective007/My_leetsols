class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res=0,curr=0,cntb=0,a=0,b=0;
        for(auto c:fruits){
            if(c==a||c==b){
                curr+=1;
            }else{
                curr=cntb+1;
            }
            if(c==b){
                cntb++;
            }else{
                cntb=1;
            }
            if(b!=c){
                a=b;
                b=c;
            }
            res=max(res,curr);
        }
        return res;
    }
};