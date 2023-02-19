class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;;
        for(auto x:nums){
            temp.push_back(x);
        }
        for(int i=0;i<nums.size();i++){
            nums[(i+k)%nums.size()]=temp[i];
        }
    }
};