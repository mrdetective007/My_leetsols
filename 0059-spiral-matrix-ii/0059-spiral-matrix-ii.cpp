class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans,matrix(n,vector<int> (n));
        int val=1;
        int left=0,right=n-1;
        int top=0,bottom=n-1;
        int dir=1;
        while(left<=right&&top<=bottom){
            if(dir==1){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=val;
                    val++;
                }
                dir=2;
                top++;
            }
            else if(dir==2){
                for(int i=top;i<=bottom;i++){
                    matrix[i][right]=val;
                    val++;
                }
                dir=3;
                right--;
            }
            else if(dir==3){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=val;
                    val++;
                }
                dir=4;
                bottom--;
            }
            else if(dir==4){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=val;
                    val++;
                }
                dir=1;
                left++;
            }
        }
        for(auto x:matrix){
            ans.push_back(x);
        }
        return ans;
    }
};