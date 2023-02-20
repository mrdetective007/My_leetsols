class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        map<int,int> map;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            for(auto x:bank[i]){
                if(x=='1'){
                    cnt++;
                }
            }
            if(cnt){    
            map[i]=cnt;
            }
        }
        int cnt=0;
        for(auto x:map){
            if(x.second>=1){
                cnt++;
            }
        }
        if(cnt==1){
            return 0;
        }
        vector<int> vec;
        for(auto x:map){
            vec.push_back(x.second);
        }
        int ans=0;
        for(int i=1;i<vec.size();i++){
            ans+=(vec[i-1]*vec[i]);
        }
        return ans;
    }
};