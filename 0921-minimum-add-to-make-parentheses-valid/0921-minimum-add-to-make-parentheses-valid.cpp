class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int cnt=0;
        for(auto x:s){
            cout<<open<<endl;
            if(x=='('){
                open++;
            }else{
                open--;
            }
            if(open<0){
                cnt+=abs(open);
                open=0;
            }
        }
        cnt+=abs(open);
        return cnt;
    }
};