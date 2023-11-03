#define sum_vec(x) accumulate(x.begin(), x.end(), 0LL)

class Solution {
public:
    
    int ok(vector<int> &nums){
        int cnt=0;
        for(auto x: nums){
            if(x==0){
                cnt++;
            }
        }
        return cnt;
    } 

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long z1=ok(nums1),z2=ok(nums2);
        long long sum1=0,sum2=0;
        for(auto x:nums1){
            sum1+=x;
        }
        for(auto x:nums2){
            sum2+=x;
        }
        if(z1==0 && z2==0){
            if(sum1==sum2){
                return sum1;
            }
            return -1;
        }
        
        long long i=1,j=(long long)1e12;
        long long ans=-1;
        
        while(i<j){
            long long mid=i+(j-i)/2;
            long long y=mid-sum1,z=mid-sum2;
            
            if(y>=0 && z>=0 && y>=z1 && z>=z2){
                ans=mid;
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        
        if(z1==0){
            if(sum1!=ans){
                ans=-1;
            }
        }
        if(z2==0){
            if(sum2!=ans){
                ans=-1;
            }
        }      
        return ans;
    }
};