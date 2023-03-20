class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n=flowerbed.size();
        if(k==0){
            return true;
        }
        for(int i=0;i<n;i++){
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==n-1 || flowerbed[i+1]==0)){
                k--;
                if(k==0){
                    return true;
                }
                flowerbed[i]=1;
            }
        }
        return false;
    }
};