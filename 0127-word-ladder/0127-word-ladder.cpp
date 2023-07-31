class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(auto x:wordList){
            s.insert(x);
        }
        queue<string> q;
        q.push(beginWord);
        int l=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                if(curr==endWord){
                    return l;
                }
                s.erase(curr);
                for(int j=0;j<curr.size();j++){
                    char c=curr[j];
                    for(int k=0;k<26;k++){
                        curr[j]=k+'a';
                        if(s.find(curr)!=s.end()){
                            q.push(curr);
                        }
                    }
                    curr[j]=c;
                }
            }
            l++;
        }
        return 0;
    }
};