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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        for(int i=0;i<k;i++){
            if(temp == nullptr) return head;
            temp = temp->next;
        }
        ListNode *cur = head,*prev = nullptr, *next = nullptr;
        for(int i=0;i<k;i++){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = reverseKGroup(cur,k);
        return prev;
    }
};