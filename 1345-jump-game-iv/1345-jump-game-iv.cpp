class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int cnt=0;
        queue<int> q;
        vector<int> vis(arr.size(),0);
        vis[0]=1;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();
                if(curr==arr.size()-1){
                    return cnt;
                }
                vector<int> &vec=mp[arr[curr]];
                vec.push_back(curr-1);
                vec.push_back(curr+1);
                for(auto x:vec){
                    if(x>=0 && x<arr.size() && vis[x]==0){
                        vis[x]=1;
                        q.push(x);
                    }
                }
                vec.clear();
            }
            cnt++;
        }
        return cnt;
    }
};