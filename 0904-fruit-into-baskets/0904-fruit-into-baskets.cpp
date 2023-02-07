class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> map;
        int i,j;
        for(i=0,j=0;j<fruits.size();j++){
            map[fruits[j]]++;
            if(map.size()>2){
                if(--map[fruits[i]]==0){
                    map.erase(fruits[i]);
                }
                i++;
            }
        }
        return j-i;
    }
};