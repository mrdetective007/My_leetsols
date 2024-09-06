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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp=new ListNode(0,head);
        set<int> s;
        for(auto x:nums){
            s.insert(x);
        }
        for(auto it=temp;it->next!=NULL;){
            if(s.contains(it->next->val)){
                it->next=it->next->next;
            }
            else{
                it=it->next;
            }
        }
        return temp->next;
    }
};