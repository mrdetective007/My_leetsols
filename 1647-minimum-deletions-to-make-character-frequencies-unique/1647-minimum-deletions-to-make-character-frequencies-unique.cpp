class Solution {
public:
    
    static bool cmp(pair<char,int> a,pair<char,int> b){
        return a.second>b.second;
    }
    
    
    int minDeletions(string s) {
        map<char,int> m;
        for(auto x:s){
            m[x]++;
        }
        vector<pair<char,int>> vec;
        for(auto x:m){
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end(),cmp);
        set<int> st;
        int cnt=0;
        for(auto x:vec){
            while(x.second>0 && st.count(x.second)){
                cnt++;
                x.second--;
            }
            st.insert(x.second);
        }
        return cnt;
    }
};