class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double> time(n);
        for(int i=0;i<n;i++){
            time[i]=ceil((double)dist[i]/speed[i]);
        }
        sort(time.begin(),time.end());
        int m=0,i=0;
        while(i<n && time[i]>m){
            m++;
            i++;
        }
        return m;
    }
};