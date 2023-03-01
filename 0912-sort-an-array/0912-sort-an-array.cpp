class Solution {
public:
    
    void merging(vector<int> &nums,int low,int mid,int high){
        if(low>=high){
            return;
        }
        int i=low,j=mid+1,k=0,size=high-low+1;
        vector<int> vec(size);
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                vec[k++]=nums[i++];
            }else{
                vec[k++]=nums[j++];
            }
        }
        while(i<=mid){
            vec[k++]=nums[i++];
        }
        while(j<=high){
            vec[k++]=nums[j++];
        }
        for(k=0;k<size;k++){
            nums[k+low]=vec[k];
        }
    }
    
    void msorting(vector<int>&nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=low+(high-low)/2;
        msorting(nums,low,mid);
        msorting(nums,mid+1,high);
        merging(nums,low,mid,high);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        msorting(nums,low,high);
        return nums;
    }
};