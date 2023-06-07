class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;
        for (int i = 0; i < 31; i++) {
            int amask = (1 << i) & a;
            int bmask = (1 << i) & b;
            int cmask = (1 << i) & c;
            if (cmask > 0 && (amask == 0 && bmask == 0)) {
			    // toggle one bit either in a or in b
                answer++;
            } else if (cmask == 0 && (amask > 0 && bmask > 0)) {
			    // toggle both bits in a and in b to make `0 | 0 == 0`
                answer += 2;
            } else if (cmask == 0 && (amask > 0 || bmask > 0)) {
			    // toggle the bit which is on whether it is in `a` or in `b`
                answer++;
            }
        }
        return answer;
    }
};