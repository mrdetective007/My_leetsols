class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ele=*max_element(nums.begin(),nums.end());
        int maxi=0,len=0;
        for(auto x:nums){
            if(x==ele){
                maxi=max(maxi,++len);
            }else{
                len=0;
            }
        }
        return maxi;
    }
};