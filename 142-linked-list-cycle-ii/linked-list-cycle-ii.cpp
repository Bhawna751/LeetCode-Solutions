/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return nullptr;
        ListNode *fast=head,*slow=head,*entry=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                while(slow!=entry){
                    slow=slow->next;
                    entry =entry->next;
                }
                return entry;
            }

        }
        return nullptr;
    }
};