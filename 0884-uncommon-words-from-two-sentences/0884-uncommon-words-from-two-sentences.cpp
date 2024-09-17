class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>m;
        stringstream ss(s1);
        string temp;
        while(ss>>temp){
            m[temp]++;
        }
        stringstream sst(s2);
        temp="";
        map<string,int>mt;
        while(sst>>temp){
            mt[temp]++;
        }
        // for(auto x:m){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // for(auto x:mt){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        vector<string> vec;
        for(auto x:m){
            if(x.second==1 && !mt[x.first]){
                vec.push_back(x.first);
            }
        }
        for(auto x:mt){
            if(x.second==1 && !m[x.first]){
                vec.push_back(x.first);
            }
        }
        return vec;
    }
};