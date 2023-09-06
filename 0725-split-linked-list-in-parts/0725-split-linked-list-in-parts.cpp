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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        vector<ListNode*> vec;
        int num=n/k;
        int extra=n%k;
        temp=head;
        while(temp){
            vec.push_back(temp);
            int currlen=1;
            while(currlen<num){
                temp=temp->next;
                currlen++;
            }
            if(extra>0 && n>k){
                temp=temp->next;
                extra--;
            }
            ListNode* x=temp->next;
            temp->next=nullptr;
            temp=x;
        }
        while(n<k){
            vec.push_back(nullptr);
            n++;
        }
        return vec;
    }
};