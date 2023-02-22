class Solution {
public:
    bool ok(vector<int> &weights, int days, int mid){
        int day=1;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum>mid){
                sum=weights[i];
                day+=1;
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int i=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(auto x:weights){
            sum+=x;
        }
        int j=sum;
        int ans=0;
        while(i<j){
            int mid=i+(j-i)/2;
            if(ok(weights,days,mid)){
                //ans=mid;
                //j=mid-1;
                j=mid;
            }else{
                i=mid+1;
            }
        }
        if(weights.size()==days){
            return i;
        }
        ///return ans;
        return i;
    }
};