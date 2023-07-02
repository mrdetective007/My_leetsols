class Solution {
public:
    vector<int> sl(vector<int> vec){
        int n=vec.size();
        vector<int> nsl;
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                nsl.push_back(-1);
            }
            else if(!s.empty() && s.top().first<vec[i]){
                nsl.push_back(s.top().second);
            }else{
                while(!s.empty() && s.top().first>=vec[i]){
                    s.pop();
                }
                if(s.empty()){
                    nsl.push_back(-1);
                }else{
                    nsl.push_back(s.top().second);
                }
            }
            s.push({vec[i],i});
        }
        return nsl;
    }
    
    vector<int> sr(vector<int> vec){
        int n=vec.size();
        vector<int> nsr;
        stack<pair<int,int>> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                nsr.push_back(n);
            }
            else if(!s.empty() && s.top().first<vec[i]){
                nsr.push_back(s.top().second);
            }else{
                while(!s.empty() && s.top().first>=vec[i]){
                    s.pop();
                }
                if(s.empty()){
                    nsr.push_back(n);
                }else{
                    nsr.push_back(s.top().second);
                }
            }
            s.push({vec[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        return nsr;
    }
    
    int mah(vector<int> vec){
        int n=vec.size();
        vector<int> nsl=sl(vec);
        vector<int> nsr=sr(vec);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=(nsr[i]-nsl[i]-1)*vec[i];
        }
        return *max_element(ans.begin(),ans.end());
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> vec;
        for(auto x:matrix){
            vector<int> t;
            for(auto y:x){
                t.push_back(y-'0');
            }
            vec.push_back(t);
        }
        vector<int> temp;
        for(int i=0;i<m;i++){
            temp.push_back(vec[0][i]);
        }
        int maxi=mah(temp);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]==0){
                    temp[j]=0;
                }else{
                    temp[j]+=vec[i][j];
                }
            }
            maxi=max(maxi,mah(temp));
        }
        return maxi;
    }
};