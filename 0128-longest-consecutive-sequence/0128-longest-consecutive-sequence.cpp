class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set;
        for(auto x:nums){
            set.insert(x);
        }
        int longest=0;
        for(auto x:nums){
            if(set.find(x-1)==set.end()){
                int length=0;
                while(set.find(x+length)!=set.end()){
                    length++;
                }
                longest=max(length,longest);
            }
        }
        return longest;
    }
};