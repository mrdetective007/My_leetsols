class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        return (ceil(log10(n)/0.60205999132796239042747778944899) == floor(log10(n)/0.60205999132796239042747778944899));
    }
};