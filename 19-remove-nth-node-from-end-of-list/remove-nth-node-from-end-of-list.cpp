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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr){
            return nullptr;
        }
        int size=0;
        ListNode *q=head;
        for(;q!=nullptr;q=q->next){
                size++;
        }
        if(size == n){
            ListNode* p = head->next;
            head = head->next;
            return p;
        }
        int cur = size-n;
        q=head;
        while( q!= nullptr){
            cur--;
            if(cur == 0){
                break;
            }
            q = q->next;
        }
        ListNode *del = q->next;
        q->next = q->next->next;
        del = del->next;
        return head;
    }
};