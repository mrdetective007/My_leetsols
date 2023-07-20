class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        for(auto x:asteroids){
            if(x>0){
                s.push(x);
            }else{
                while(!s.empty() && s.top()>0 && s.top()<(abs(x))){
                    s.pop();
                }
                if(!s.empty() && s.top()==abs(x)){
                    s.pop();
                }
                else if(s.empty() || s.top()<0){
                    s.push(x);
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};