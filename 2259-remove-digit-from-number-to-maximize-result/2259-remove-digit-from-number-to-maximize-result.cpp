class Solution {
public:
    
    static bool cmp(string a,string b){
        return a+b>b+a;
    }
    
    string removeDigit(string number, char digit) {
        vector<int>indices;
        for(int i=0;i<number.size();i++){
            if(number[i]==digit){
                indices.push_back(i);
            }
        }
        vector<string> s;
        for(int i=0;i<indices.size();i++){
            string t="";
            for(int j=0;j<number.size();j++){
                if(j==indices[i]){
                    continue;
                }
                t+=number[j];
            }
            s.push_back(t);
        }
        sort(s.begin(),s.end(),cmp);
        return s[0];
    }
};