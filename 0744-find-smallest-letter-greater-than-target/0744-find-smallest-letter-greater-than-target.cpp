class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> vec;
        for(auto x:letters){
            vec.push_back(x-'a');
        }
        int tar=target-'a';
        sort(vec.begin(),vec.end());
        auto it=upper_bound(vec.begin(),vec.end(),tar);
        if(it==vec.end()){
            return letters[0];
        }
        return *it+'a';
    }
};