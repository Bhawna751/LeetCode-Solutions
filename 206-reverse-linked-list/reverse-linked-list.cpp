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
     
     ListNode *q=head , *prev = nullptr, *next = nullptr;
     
     while(q!=nullptr){
        next = q->next;
        q->next=prev;
        prev=q;
        q=next;
     }   
     return prev;
    }
};