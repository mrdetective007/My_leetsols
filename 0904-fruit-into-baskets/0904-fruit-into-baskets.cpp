class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> map;
        int start=0,end=0;
        while(end<fruits.size()){
            map[fruits[end]]++;
            if(map.size()>2){
                if(--map[fruits[start]]==0){
                    map.erase(fruits[start]);
                }
                start++;
            }
            end++;
        }
        return end-start;
    }
};