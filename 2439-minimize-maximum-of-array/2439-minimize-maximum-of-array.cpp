class Solution {
public:
    
    bool ok(vector<int>nums,int maxi){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>(long long)maxi*(i+1)){
                return false;
            }
        }
        return true;
    }
    
    int solve(vector<int> nums){
        int l=0,h=*max_element(nums.begin(),nums.end());
        while(l<h){
            int mid=l+(h-l)/2;
            if(ok(nums,mid)){
                h=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        if(nums.size()==2){
            return *max_element(nums.begin(),nums.end());
        }
        int ans=solve(nums);
        return ans;
    }
};