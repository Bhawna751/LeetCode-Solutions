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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *dummy1 = headA,*dummy2 = headB;
        while(dummy1 != dummy2){
            if(dummy1==nullptr) dummy1 = headB;
            else dummy1 = dummy1->next;
            if(dummy2==nullptr) dummy2 = headA;
            else dummy2 = dummy2->next;
        }
        return dummy2; 
    }
};