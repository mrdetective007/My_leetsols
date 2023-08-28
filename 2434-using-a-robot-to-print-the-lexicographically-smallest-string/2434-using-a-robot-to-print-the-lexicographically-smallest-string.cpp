class Solution {
public:
    
    char less(vector<int> &v){
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                return i+'a';
            }
        }
        return 'a';
    }
    
    string robotWithString(string s) {
        stack<char> st;
        string ans="";
        vector<int>v(26,0);
        for(auto x:s){
            v[x-'a']++;
        }
        for(auto x:s){
            st.push(x);
            v[x-'a']--;
            while(!st.empty() && st.top()<=less(v)){
                ans.push_back(st.top());
                st.pop();
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};