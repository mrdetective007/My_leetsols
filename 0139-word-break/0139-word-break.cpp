class Solution {
private:
    bool wordBreak(string s, unordered_set<string> &set, vector<int> &memo, int j){
        if(j == s.size()){
            return true;
        }
        if(memo[j] != -1){
            return memo[j];
        }
        for(int i=j; i<s.size(); i++){
            if(set.count(s.substr(j, i-j+1)) && wordBreak(s, set, memo, i+1)){
                memo[j] = true;
                return true;
            }
        }
        return memo[j] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set, memo, 0);
    }
};