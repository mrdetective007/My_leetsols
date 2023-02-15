class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int> temp;
        vector<int> ans;
        while(k>0){
            int rem=k%10;
            temp.push_back(rem);
            k/=10;
        }
        int n=max(nums.size(),temp.size());
        reverse(nums.begin(),nums.end());
        //reverse(temp.begin(),temp.end());
        if(nums.size()!=n){
            while(nums.size()<n){
                nums.push_back(0);
            }
        }
        if(temp.size()!=n){
            while(temp.size()<n){
                temp.push_back(0);
            }
        }
        int carry=0;
        for(int i=0;i<n;i++){
            int sum=nums[i]+temp[i]+carry;
            if(sum>=10){
                carry=1;
                sum%=10;
            }else{
                carry=0;
            }
            ans.push_back(sum);
        }
        if(carry){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};