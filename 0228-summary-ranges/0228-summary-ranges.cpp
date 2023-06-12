class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        vector<pair<int,int>> vec;
        vec.push_back({nums[0],nums[0]});
        for(int i=1;i<nums.size();i++){
            if((long long)nums[i]-(long long)vec.back().second==1LL){
                vec.back().second=max(vec.back().second,nums[i]);
            }else{
                vec.push_back({nums[i],nums[i]});
            }
        }
        vector<string> ans;
        for(auto x:vec){
            if(x.first==x.second){
                ans.push_back(to_string(x.first));
            }else{
                ans.push_back(to_string(x.first)+"->"+to_string(x.second));
            }
        }
        return ans;
        // for(auto x:vec){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // return {};
    }
};