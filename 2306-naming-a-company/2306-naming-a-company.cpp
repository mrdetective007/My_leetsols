class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        set<string> vec[26];
        for(auto x:ideas){
            vec[x[0]-'a'].insert(x.substr(1));
        }
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                int same=0;
                for(auto x:vec[i]){
                    if(vec[j].find(x)!=vec[j].end()){
                        same++;
                    }
                }
            ans+=(long long)2*(vec[i].size()-same)*(vec[j].size()-same);
            }
        }
        return ans;
    }
};