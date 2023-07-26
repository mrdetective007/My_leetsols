class Solution {
public:
    
    bool ok(vector<int> nums,double hour,int mid){
        double sum=0;
        for(int i=0;i<nums.size()-1;i++){
            sum+=ceil((double)nums[i]/mid);
            // sum+=nums[i]/mid;
        }
        sum+=(double)nums[nums.size()-1]/mid;
        return sum<=hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=1e7;
        if(ceil(hour)<dist.size()){
            return -1;
        }
        while(l<r){
            int mid=l+(r-l)/2;
            if(ok(dist,hour,mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return r;
    }
};