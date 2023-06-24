class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int remain=(long long)target-(nums[i]+nums[j]);
                int l=j+1,r=n-1;
                while(l<r){
                    if(nums[l]+nums[r]==remain){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l<r && nums[l-1]==nums[l]){
                            l++;
                        }
                        while(l<r && nums[r]==nums[r+1]){
                            r--;
                        }
                    }
                    else if(nums[l]+nums[r]>remain){
                        r--;
                    }else{
                        l++;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};