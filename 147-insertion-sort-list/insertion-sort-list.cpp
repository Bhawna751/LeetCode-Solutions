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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *q= new ListNode(0);
        q->next=head;
        ListNode *prev=q, *cur=head;
        while(cur!=nullptr){
            if(cur->next!=nullptr && cur->next->val < cur->val){
                while(prev->next!=nullptr && prev->next->val < cur->next->val) prev=prev->next;
                ListNode* temp = prev->next;
                prev->next = cur->next;
                cur->next=cur->next->next;
                prev->next->next = temp;
                prev=q;

            }
            else cur=cur->next;
            
        }
        return q->next;
    }
};