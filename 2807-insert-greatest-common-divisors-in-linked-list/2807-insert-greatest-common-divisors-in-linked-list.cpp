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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp && temp->next){
            int a=temp->val;
            int b=temp->next->val;
            int g=__gcd(a,b);
            ListNode* newnode=new ListNode(g);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }
        return head;
    }
};