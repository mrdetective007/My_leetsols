class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=0;
        for(auto x:rolls){
            sum+=x;
        }
        int remsum=((n+m)*mean)-sum;
        if(remsum<n || remsum>(6*n)){
            return {};
        }
        int val=remsum/n;
        int remval=remsum%n;
        vector<int> vec(n,val);
        for(int i=0;i<remval;i++){
            vec[i]++;
        }
        return vec;
    }
};