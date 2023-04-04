class Solution {
public:
    
    bool ok(int a,int b,long long success){
        if((long long)a*(long long)b>=success){
            return true;
        }
        return false;
    }
    
    int solve(int a,vector<int>&potions,long long success){
        int n=potions.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(ok(a,potions[mid],success)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return n-l;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();i++){
            int a=solve(spells[i],potions,success);
            ans.push_back(a);
        }
        return ans;
    }
};