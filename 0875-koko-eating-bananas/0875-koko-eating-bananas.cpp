class Solution {
public:
    
    bool ok(vector<int> &piles, int h, int mid){
        long long int hours=0;
        for(int i=0;i<piles.size();i++){
            int div = ceil(piles[i]*1.0/mid);
            hours+=div;
        }
        return hours<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        if(piles.size()==h){
            return j;
        }
        while(i<j){
            int mid=i+(j-i)/2;
            if(ok(piles,h,mid)){
                j=mid;
            }else{
                i=mid+1;
            }
        }
        return i;
    }
};