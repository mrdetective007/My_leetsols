class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0,sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if((sum/k)>=threshold){
            cnt++;
        }
        for(int i=k;i<arr.size();i++){
            sum-=arr[i-k];
            sum+=arr[i];
            if((sum/k)>=threshold){
                cnt++;
            }
        }
        return cnt;
    }
};