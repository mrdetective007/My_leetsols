class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int i=0,j=piles.size()-1;
        int cnt=0;
        while(j-i>=2){
            cnt+=piles[i+1];
            i+=2;
            j--;
        }
        return cnt;
    }
};
// 987654321
//864
//122478
//27