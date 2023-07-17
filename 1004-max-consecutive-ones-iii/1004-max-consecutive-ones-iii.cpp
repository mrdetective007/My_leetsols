class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int i=0;
        int j=0;
        int count=0;
        int maxi=0;

        while(j<nums.size()){

            if(nums[j]==0){
                count++;            
            }
             if(count<=k && j< nums.size()){     
                 maxi=max(maxi,j-i+1);        
                 j++;
             }
             else if(count>k){             
                 while(count>k){             
                     if(nums[i]==0){        
                         count--; 
                     }
                     i++;
                 }       
                 j++;
             }
            
        }
        return maxi;
        
    }
};