class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> vec(right+1,1);
        vec[0]=vec[1]=0;
        for(int i=2;i*i<=right;i++){
            if(vec[i]){
                for(int j=i*i;j<=right;j+=i){
                    vec[j]=0;
                }
            }
        }
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(vec[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0||ans.size()==1){
            return {-1,-1};
        }
        vector<int> temp;
        int mini=INT_MAX,res=0;
        for(int i=1;i<ans.size();i++){
            if(ans[i]-ans[i-1]<mini){
                mini=ans[i]-ans[i-1];
                res=i;
            }
        }
        temp.push_back(ans[res-1]);
        temp.push_back(ans[res]);
        return temp;
    }
};