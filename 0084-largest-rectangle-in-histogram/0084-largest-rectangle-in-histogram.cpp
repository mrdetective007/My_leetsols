class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        nums.push_back(0);
        int maxi=0;
        stack<int> ind;
        for(int i=0;i<nums.size();i++){
            while(!ind.empty() && nums[ind.top()]>nums[i]){
                int h=nums[ind.top()];
                ind.pop();
                int b;
                if(ind.empty()==true){
                    b=-1;
                }else{
                    b=ind.top();
                }
                int area=h*(i-b-1);
                maxi=max(area,maxi);
            }
            ind.push(i);
        }
        return maxi;
    }
};