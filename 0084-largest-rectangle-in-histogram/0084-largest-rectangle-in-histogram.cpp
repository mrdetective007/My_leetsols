class Solution {
public:
    
    vector<int> sl(vector<int> heights){
        int n=heights.size();
        stack<pair<int,int>> s;
        vector<int> nsl;
        for(int i=0;i<n;i++){
            if(s.empty()){
                nsl.push_back(-1);
            }
            else if(!s.empty() && s.top().first<=heights[i]){
                nsl.push_back(s.top().second);
            }else{
                while(!s.empty() && s.top().first>heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    nsl.push_back(-1);
                }else{
                    nsl.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        return nsl;
    }
    
    vector<int> sr(vector<int> heights){
        int n=heights.size();
        stack<pair<int,int>> s;
        vector<int> nsr;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                nsr.push_back(n);
            }
            else if(!s.empty() && s.top().first<heights[i]){
                nsr.push_back(s.top().second);
            }else{
                while(!s.empty() && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    nsr.push_back(n);
                }else{
                    nsr.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        return nsr;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nsl=sl(heights);
        vector<int> nsr=sr(heights);
        // for(auto x:nsl){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:nsr){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=(nsr[i]-nsl[i]-1)*heights[i];
        }
        return *max_element(ans.begin(),ans.end());
    }
};