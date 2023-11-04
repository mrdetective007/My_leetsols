class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=max_element(left.begin(),left.end())!=left.end()?*max_element(left.begin(),left.end()):0;
        int r=min_element(right.begin(),right.end())!=right.end()?*min_element(right.begin(),right.end()):n;
        return max(l,n-r);
    }
};