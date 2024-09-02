class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long sum=0;
        for(auto x:chalk){
            sum+=x;
        }
        k%=sum;
        int i=0;
        while(k>0){
            if(k<chalk[i%n]){
                break;
            }
            k-=chalk[i%n];
            i++;
        }
        return i%n;
    }
};