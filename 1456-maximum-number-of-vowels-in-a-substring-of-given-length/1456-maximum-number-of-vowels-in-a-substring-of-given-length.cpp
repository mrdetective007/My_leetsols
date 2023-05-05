class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> vec(26);
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            vec[s[i]-'a']++;
        }
        int j=0;
        int start=0;
        maxi=max(maxi,vec[0]+vec[4]+vec[8]+vec[14]+vec[20]);
        for(int i=k;i<s.size();i++){
            start=s[j]-'a';
            // cout<<start<<endl;
            vec[start]--;
            j++;
            vec[s[i]-'a']++;
            maxi=max(maxi,vec[0]+vec[4]+vec[8]+vec[14]+vec[20]);
        }
        // for(auto x:vec){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        return maxi;
    }
};