class Solution {
public:
    int minBitFlips(int start, int goal) {
        /*
            The question asks for the number of places where the bit is differing
            Now, once you do xor of both the numbers, the number of places where
            1 occurs denotes the number of places where the bit differs,
            so, basically have to calculate the differing positions
        */
        int x=start^goal;
        int cnt=0;
        while(x!=0){
            cnt+=x&1;
            x>>=1;//shifting the bit one position right
        }
        return cnt;
    }
};