class Solution {
public:
    string largestGoodInteger(string num) {
        char res=0;
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                res=max(res,num[i]);
            }
        }
        string s="";
        for(int i=0;i<3;i++){
            s.push_back(res);
        }
        return res==0?"":s;
    }
};