class Solution {
public:
    bool ok(vector<int>& time, long long int mid, int totalTrips){
        long long int pep=0;
        for(long long int i=0;i<time.size();i++){
            long long int x=time[i];
            pep+=((mid)/x);
        }
        return pep>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int n=time.size() ;
        long long int i=1;
        long long int j=1e14;
        while(i<j){
            long long int mid=i+(j-i)/2;
            if(ok(time,mid,totalTrips)){
                j=mid;
            }else{
                i=mid+1;
            }
        }
        return i;
    }
};