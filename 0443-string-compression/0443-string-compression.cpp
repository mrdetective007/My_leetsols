class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>temp;
        char x=chars[0];
        int j=0;
        int i=1;
        for(;i<chars.size();i++){
            if(chars[i]==x){
                continue;
            }else{
                temp.push_back(x);
                x=chars[i];
                if(i-j>1){
                    string json=to_string(i-j);
                    for(auto x:json){
                        temp.push_back(x);
                    }
                }
                j=i;
            }
        }
        temp.push_back(x);
        if(i-j>1){
            string json=to_string(i-j);
            for(auto x:json){
                temp.push_back(x);
            }
        }
        chars.clear();
        for(auto x:temp){
            chars.push_back(x);
        }
        return chars.size();
    }
};