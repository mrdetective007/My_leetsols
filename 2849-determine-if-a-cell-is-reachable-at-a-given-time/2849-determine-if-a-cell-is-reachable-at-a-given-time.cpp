class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int cnt=max(abs(fx-sx),abs(fy-sy));
        return cnt>0?cnt<=t:t!=1;
    }
};