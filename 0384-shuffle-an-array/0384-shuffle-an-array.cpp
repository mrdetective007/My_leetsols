class Solution {
public:
    vector<int> vec,temp;
    Solution(vector<int>& nums) {
        for(auto x:nums){
            vec.push_back(x);
        }
    }
    
    vector<int> reset() {
        return vec;
    }
    
    vector<int> shuffle() {
        temp.clear();
        for(auto x:vec){
            temp.push_back(x);
        }
        for(int i=vec.size()-1;i>0;i--){
            int j=rand()%(i+1);
            swap(temp[i],temp[j]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */