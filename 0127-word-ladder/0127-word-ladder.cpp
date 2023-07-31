class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr.first==endWord){
                return curr.second;
            }
            for(int i=0;i<curr.first.size();i++){
                char c=curr.first[i];
                for(int j=0;j<26;j++){
                    curr.first[i]='a'+j;
                    if(s.find(curr.first)!=s.end()){
                        s.erase(curr.first);
                        q.push({curr.first,curr.second+1});
                    }
                }
                curr.first[i]=c;
            }
        }
        return 0;
    }
};