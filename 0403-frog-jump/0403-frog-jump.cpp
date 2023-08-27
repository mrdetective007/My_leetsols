class Solution {
public:
    unordered_map<int,bool> mp;
    bool recursion(int pos, int prevStep, vector<int>& arr, int n, map<pair<int,int>,bool>& memo){

        if(mp[pos]== false || pos > arr[n-1]) return false;
        if(pos == arr[n-1]) return true;  
        if(memo.find({pos,prevStep}) != memo.end()) return memo[{pos,prevStep}];

        bool isPossible;

        if(pos==0){
            isPossible = recursion(pos+1,1,arr,n,memo);
        }
        else{
            if(prevStep-1>0) 
                isPossible = recursion(pos+(prevStep-1),prevStep-1,arr,n,memo);
            if(isPossible) return true;
            isPossible = recursion(pos+prevStep,prevStep,arr,n,memo);
            if(isPossible) return true;
            isPossible = recursion(pos+(prevStep+1),prevStep+1,arr,n,memo);
            if(isPossible) return true;
        }
        
        memo[{pos,prevStep}] = isPossible;
        return isPossible;

    }

    bool canCross(vector<int>& stones) {
        
        for(auto itr : stones){ 
            mp[itr] = true;
           
        }
        map<pair<int,int>,bool> memo;
        int n = stones.size();
        return recursion(0,1,stones,n,memo);
    }
};