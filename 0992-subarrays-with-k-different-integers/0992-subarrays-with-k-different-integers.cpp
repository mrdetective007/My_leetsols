class Solution {
public:
    
    int solve(vector<int> &nums, int k){
        unordered_map<int,int>m;
        int i=0,j=0;
        int cnt=0;
        while(j<nums.size()){
            m[nums[j]]++;
            if(m.size()<=k){
                cnt+=j-i;
                j++;
            }
            else if(m.size()>k){
                while(m.size()>k){
                    m[nums[i]]--;
                    if(m[nums[i]]==0){
                        m.erase(nums[i]);
                    }
                    i++;
                }
                if(m.size()<=k){
                    cnt+=j-i;
                }
                j++;
            }
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};