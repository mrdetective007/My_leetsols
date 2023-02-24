/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vec(m,vector<int> (n,-1));
        int l=0,r=n-1;
        int t=0,b=m-1;
        int dir=1;
        while((l<=r && t<=b)&&head!=NULL){
            if(dir==1){
                for(int i=l;i<=r&&head;i++){
                    vec[t][i]=head->val;
                    head=head->next;
                }
                dir=2;
                t++;
            }
            else if(dir==2){
                for(int i=t;i<=b&&head;i++){
                    vec[i][r]=head->val;
                    head=head->next;
                }
                dir=3;
                r--;
            }
            else if(dir==3){
                for(int i=r;i>=l&&head;i--){
                    vec[b][i]=head->val;
                    head=head->next;
                }
                dir=4;
                b--;
            }
            else if(dir==4){
                for(int i=b;i>=t&&head;i--){
                    vec[i][l]=head->val;
                    head=head->next;
                }
                dir=1;
                l++;
            }
        }
        return vec;
    }
};