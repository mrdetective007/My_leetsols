class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(auto x:s){
            m[x]++;
        }
        char ans;
        for(auto x:t){
            if(m.find(x)==m.end()){
                ans=x;
                break;
            }else{
                m[x]--;
                if(m[x]==0){
                    m.erase(x);
                }
            }
        }
        return ans;
    }
};