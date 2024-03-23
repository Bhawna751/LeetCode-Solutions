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
    void reorderList(ListNode* head) {
        if(head == nullptr)return;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next) slow = slow->next;
        while(slow){
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }
        slow = prev;
        while(head && slow){
            fast = head->next;
            prev = slow->next;
            head->next = slow;
            slow->next = fast;
            head = fast;
            slow = prev;
        }
        if(head && head->next) head->next->next = nullptr;
    }
};