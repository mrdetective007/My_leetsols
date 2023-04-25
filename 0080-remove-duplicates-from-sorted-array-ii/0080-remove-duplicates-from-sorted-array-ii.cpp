class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3){
            return nums.size();
        }
        int in=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[in-2]){
                nums[in++]=nums[i];
            }
        }
        return in;
    }
};