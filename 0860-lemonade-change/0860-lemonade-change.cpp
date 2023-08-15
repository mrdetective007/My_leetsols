class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,tty=0;
        for(auto x:bills){
            if(x==5){
                five++;
            }
            else if(x==10){
                ten++;
                five--;
            }
            else if(x==20 && ten>0){
                ten--;
                five--;
            }else{
                five-=3;
            }
            if(five<0){
                return false;
            }
        }
        return true;
    }
};