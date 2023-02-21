class Solution {
public:
    bool checkPowersOfThree(int n) {
        int k=n;
        vector<int> vec;
        while(k>0){
            int rem=k%3;
            vec.push_back(rem);
            k/=3;
        }
        for(auto x:vec){
            if(x!=1 && x!=0){
                return false;
            }
        }
        return true;
    }
};