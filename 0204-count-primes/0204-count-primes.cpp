class Solution {
public:
    int countPrimes(int n) {
        if(n==0||n==1){
            return 0;
        }
        // if(n==2){
        //     return 0;
        // }
        vector<int> vec(n+1,1);
        vec[0]=vec[1]=0;
        for(int i=2;i*i<=n;i++){
            if(vec[i]){
                for(int j=i*i;j<=n;j+=i){
                    vec[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i]==1){
                cnt++;
            }
        }
        return cnt;
    }
};