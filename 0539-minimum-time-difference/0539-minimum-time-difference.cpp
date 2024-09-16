class Solution {
public:
    
    static bool cmp(int a, int b){
        return a-b<b-a;
    }
    
    int findMinDifference(vector<string>& timePoints) {
        int mini=INT_MAX;
        vector<int> vec;
        for(auto x:timePoints){
            int h=stoi(x.substr(0,2));
            int m=stoi(x.substr(3,2));
            vec.push_back((h*60)+m);
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=1;i<vec.size();i++){
            mini=min(mini,vec[i]-vec[i-1]);
        }
        int c = vec[0]+(1440-vec[vec.size()-1]);
        return min(mini,c);
    }
};