class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> n1,n2;
        for(auto x:a){
            n1.push_back((int)(x-48));
        }
        for(auto x:b){
            n2.push_back((int)(x-48));
        }
        int n=max(n1.size(),n2.size());
        if(n1.size()!=n){
            while(n1.size()<n){
                n1.insert(n1.begin(),0);
            }
        }
        if(n2.size()!=n){
            while(n2.size()<n){
                n2.insert(n2.begin(),0);
            }
        }
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        vector<int> vec;
        int carry=0;
        for(int i=0;i<n1.size();i++){
            int sum=n1[i]+n2[i]+carry;
            if(sum>=2){
                sum%=2;
                carry=1;
            }else{
                carry=0;
            }
            vec.push_back(sum);
        }
        if(carry==1){
            vec.push_back(1);
        }
        reverse(vec.begin(),vec.end());
        string ans="";
        for(auto x:vec){
            ans+=to_string(x);
        }
        return ans;
    }
};