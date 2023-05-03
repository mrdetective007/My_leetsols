class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> vec;
        set<int> s,aux;
        for(auto x:nums2){
            s.insert(x);
        }
        vector<int> vec1;
        for(auto x:nums1){
            if(!s.count(x)){
                aux.insert(x);
            }
        }
        for(auto x:aux){
            vec1.push_back(x);
        }
        vec.push_back(vec1);
        s.clear();
        aux.clear();
        for(auto x:nums1){
            s.insert(x);
        }
        vector<int> vec2;
        for(auto x:nums2){
            if(!s.count(x)){
                aux.insert(x);
            }
        }
        for(auto x:aux){
            vec2.push_back(x);
        }
        vec.push_back(vec2);
        return vec;
    }
};