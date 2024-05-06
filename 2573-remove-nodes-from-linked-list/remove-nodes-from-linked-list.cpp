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
ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *last=reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* newHead = reverseList(head);
        int maxi = newHead->val;
        ListNode *p = newHead,*q = newHead->next,*r;
        while(q!=nullptr){
            r=q->next;
            if(q->val < maxi){
                p->next = r;
                q=r;
            }
            else{
                maxi = q->val;
                p=q;
                q=r;
            }
        }
        newHead = reverseList(newHead);
        return newHead;
    }
};