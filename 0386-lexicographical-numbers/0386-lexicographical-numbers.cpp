class Solution {
public:
    
    static bool cmp(string a, string b){
        return a<b;
    }
    
    vector<int> lexicalOrder(int n) {
        vector<string> vec;
        for(int i=1;i<=n;i++){
            vec.push_back(to_string(i));
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int> ans;
        for(auto x:vec){
            ans.push_back(stoi(x));
        }
        return ans;
    }
};