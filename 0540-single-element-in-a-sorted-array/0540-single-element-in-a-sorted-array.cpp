class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+((r-l)/2);
            if(mid%2==0 && nums[mid]==nums[mid+1] || mid%2 && nums[mid]==nums[mid-1]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return nums[l];
    }
};