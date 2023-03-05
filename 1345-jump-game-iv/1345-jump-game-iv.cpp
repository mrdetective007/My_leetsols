class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({arr[0],{0,0}});
        int cnt=0;
        vector<bool>vis(n,false);
        vis[0]=true;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int value=curr.first;
            int ind=curr.second.first;
            int steps=curr.second.second;
            if(ind==n-1){
                cnt=steps;
                break;
            }
            if(ind-1>0 && !vis[ind-1]){
                q.push({arr[ind-1],{ind-1,steps+1}});
                vis[ind-1]=true;
            }
            if(ind+1<n && !vis[ind+1]){
                q.push({arr[ind+1],{ind+1,steps+1}});
            }
            if(mp.find(value)!=mp.end()){
                vector<int> vec=mp[value];
                for(auto x:vec){
                    if(!vis[x]){
                        q.push({arr[x],{x,steps+1}});
                        vis[x]=true;
                    }
                }
                mp.erase(value);
            }
        }
        return cnt;
    }
};