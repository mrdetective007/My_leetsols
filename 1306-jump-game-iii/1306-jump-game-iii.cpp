class Solution {
public:
    bool isvalid(int i,int mini,int maxi){
        if(i>=mini && i<maxi){
            return true;
        }
        return false;
    }
    vector<bool> vis;
    bool dfs(map<int,pair<int,int>> &mp,int res,int start){
        if(!vis[start]){
            vis[start]=true;
        }
        if(start==res){
            return true;
        }
        auto x=mp[start];
        bool a=false,b=false;
        if(!vis[x.first]){
            a=dfs(mp,res,x.first);
        }
        if(!vis[x.second]){
            b=dfs(mp,res,x.second);
        }
        return a|b;
    }
    bool canReach(vector<int>& arr, int start) {
        map<int,pair<int,int>> map;
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            int a=i,b=i;
            if(arr[i]==0){
                res.push_back(i);
            }
            if(isvalid(i-arr[i],0,arr.size())){
                a=i-arr[i];
            }
            if(isvalid(i+arr[i],0,arr.size())){
                b=i+arr[i];
            }
            map[i]={a,b};
        }
        for(int i=0;i<res.size();i++){
            vis.clear();
            for(int j=0;j<arr.size();j++){
                vis.push_back(false);
            }
            if(dfs(map,res[i],start)){
                return true;
            }
        }
        return false;
    }
    
};