class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        // for(auto x:mp){
        //     cout<<x.first<<"->";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto &x:mp){
            reverse(x.second.begin(),x.second.end());
        }
        for(auto x:mp){
            for(auto y:x.second){
                ans.push_back(y);
            }
        }
        return ans;
    }
};