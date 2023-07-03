class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.size(),m=goal.size();
        if(n!=m){
            return false;
        }
        set<char> ss;
        for(auto x:s){
            ss.insert(x);
        }
        if(s==goal && ss.size()<m){
            return true;
        }
        vector<int> d;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
                d.push_back(i);
            }
            if(d.size()>2){
                return false;
            }
        }
        return d.size()==2 && s[d[0]]==goal[d[1]] && s[d[1]]==goal[d[0]];
    }
};