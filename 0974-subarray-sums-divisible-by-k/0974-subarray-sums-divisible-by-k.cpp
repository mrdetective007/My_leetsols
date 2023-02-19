class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> map;
        map[0]=1;
        int currsum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            int rem=currsum%k;
            if(rem<0){
                rem+=k;
            }
            res+=map[rem];
            map[rem]++;
        }
        return res;
    }
};