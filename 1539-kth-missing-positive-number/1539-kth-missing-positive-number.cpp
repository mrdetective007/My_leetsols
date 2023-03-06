class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1;
        int ans=0;
        while(k>0){
            if(find(arr.begin(),arr.end(),i)==arr.end()){
                ans=i;
                k--;
            }
            i++;
        }
        return ans;
    }
};