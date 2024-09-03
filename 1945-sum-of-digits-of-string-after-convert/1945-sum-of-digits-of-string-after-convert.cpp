class Solution {
public:
    
    int calc(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        vector<int> mp(26);
        for(int i=0;i<26;i++){
            mp[i]=i+1;
        }
        int sum=0;
        for(auto x:s){
            int n=mp[x-'a'];
            while(n>0){
                sum+=n%10;
                n/=10;
            }
        }
        k--;
        while(k--){
            // cout<<sum<<endl;
            sum=calc(sum);
        }
        return sum;
    }
};