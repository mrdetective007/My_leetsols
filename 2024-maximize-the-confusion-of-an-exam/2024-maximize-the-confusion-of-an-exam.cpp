class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int k1=k,k2=k;
        int n=answerKey.size();
        vector<int> vec1,vec2;
        for(auto x:answerKey){
            if(x=='T'){
                vec1.push_back(1);
                vec2.push_back(1);
            }else{
                vec1.push_back(0);
                vec2.push_back(0);
            }
        }
        int ans=INT_MIN;
        int j=0;
        for(int i=0;i<n;i++){
            if(vec1[i]==0){
                k1--;
            }
            while(k1<0){
                if(vec1[j]==0){
                    k1++;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        j=0;
        for(int i=0;i<n;i++){
            if(vec2[i]==1){
                k2--;
            }
            while(k2<0){
                if(vec2[j]==1){
                    k2++;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};