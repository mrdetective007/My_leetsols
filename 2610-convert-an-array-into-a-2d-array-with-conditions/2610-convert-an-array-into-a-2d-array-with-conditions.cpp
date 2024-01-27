class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(205,0);
        for(auto x:nums){
            v[x]++;
        }
        vector<vector<int>> vec;
        for(int i=1;i<=200;i++){
            vector<int> temp;
            for(int j=0;j<=200;j++){
                if(v[j]!=0){
                    temp.push_back(j);
                    v[j]--;
                }
            }
            if(n>0){
                vec.push_back(temp);
                n-=temp.size();
            }
        }
        return vec;
    }
};