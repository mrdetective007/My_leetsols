class Solution {
public:
    vector<string> ans;
    
    void solve(unordered_map<int,string> m,int j,string digit,string &s){
        if(j==digit.size()){
            ans.push_back(s);
            return;
        }
        string temp=m[digit[j]-'0'];
        for(int i=0;i<temp.size();i++){
            s.push_back(temp[i]);
            solve(m,j+1,digit,s);
            s.pop_back();            
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        string s="";
        solve(m,0,digits,s);
        if(ans.size()==1){
            ans.pop_back();
            return ans;
        }
        return ans;
    }
};