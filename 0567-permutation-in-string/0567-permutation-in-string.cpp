class Solution {
public:
    
    bool perm(string a,string b){
        unordered_map<char,int> map;
        for(int i=0;i<a.size();i++){
            map[a[i]]++;
            map[b[i]]--;
        }
        for(auto x:map){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n=s2.size(),m=s1.size();
        
        if(m>n){
            return false;
        }
        
        for(int i=0;i<=n-m;i++){
            string temp=s2.substr(i,m);
            if(perm(s1,temp)){
                return true;
            }
        }
        return false;
    }
};