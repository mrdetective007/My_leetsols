class Solution {
public:
    int minOperations(int n) {
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            vec[i]=(2*i)+1;
        }
        int mid=0;
        if(n%2){
            mid=vec[n/2];
        }else{
            mid=vec[n/2]+vec[(n/2)-1];
            mid/=2;
        }
        int cnt=0;
        for(auto x:vec){
            cnt+=abs(x-mid);
        }
        return cnt/2;
    }
};